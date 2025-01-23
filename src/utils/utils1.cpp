#include <Utils.hpp>

bool	Compare(const string &test, const string &aim, int enter)
{
	if (test.length() != aim.length())
		return (false);
	else if (enter == 0)
		return (false);
	int size = aim.size();
	int i;

	for (i = 0; i < size && aim[i] == test[i]; ++i);

	if (size == i)
		return (true);
	return (false);
}

string	Visualizer(vector<Person *>& persons)
{
	string	result = " :@";

	for (int i = 0; i < int(persons.size()); i++)
	{
		result += persons[i]->getNickName();
		if (i < int(persons.size()) - 1)
			result += " ";
	}
	return (result);
}

string getColor(int fd)
{
	string colors[] = {YELLOW, MAGENTA, WHITE, BLACK, RED, BLUE, CYAN};
	string color = colors[fd % 7];
	return color;
}

string getTime()
{
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[80];

	std::time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
	return string(buffer);
}