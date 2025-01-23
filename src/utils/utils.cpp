#include <Utils.hpp>

void	modeHandler(vector<Person *> &channel, string group, string nickname)
{
	Person	&king = *channel[0];
	for (int i = 0; i < int(channel.size()); i++)
		if (channel[i] != NULL)
			Response::createMessage().from(king).to(*channel[i]).content("MODE").addContent(group + " +o " + nickname).send();
}

void	groupMsg(Person & user, const string n_channel, const string msg)
{
	vector<Person *>	&group = start.getChannel(n_channel);

	for (int i = 0; i < int(group.size()); i++)
	{
		if (group[i] != NULL && user.getNickName() != group[i]->getNickName())
			Response::createMessage().from(user).to(*group[i]).content(msg).send();
	}
}

void printerCl(string msg, Person &user)
{
	int		fd = user.getFd();
	string	color = getColor(fd);

	cout << " ----------------------------------------" << endl;
	cout << color << " [Client " << fd << "]" << DEFAULT << endl;
	cout << " Nickname: " << user.getNickName() << endl;
	cout << getTime() << endl;
	cout << "\n " << GREEN + msg + DEFAULT  << endl;
}

void printerSrv(string msg)
{
	cout << " ----------------------------------------" << endl;
	cout << " Created: " << getTime() << endl;
	cout << "\n " << CYAN + msg  + DEFAULT << endl;
}

bool	searchCh(string target, Person &from)
{
	if (target[0] != '#')
		return (false);
	map < string, vector<Person *> > search = start.getChannels();
	std::map<std::string, vector <Person *> >::iterator it = search.begin();	

	for (; it != search.end(); it++)
	{
		if (Compare(it->first, target, 1))
		{
			for (int i = 0; i < int(it->second.size()); i++)
			{
				if (Compare(it->second[i]->getNickName(), from.getNickName(), 1))
				{
					return (true);
				}
			}
			Response::create().to(from).content(NO_MEM + target).send();
		}
	}
	return (false);
}

bool	searchCh(vector <Person *> group, string name)
{
	if (group.size() == 0)
		return (false);
	for (int i = 0; i < int(group.size()); i++)
	{
		if (group[i]->getNickName() == name)
			return (true);
	}
	return (false);
}
