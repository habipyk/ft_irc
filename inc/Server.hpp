#ifndef SERVER_HPP
#define SERVER_HPP

#include <DefineMod.hpp>
#include <Global.hpp>
#include <Response.hpp>
#include <Commands.hpp>

#define VERSION "v1.0.0"

class Server
{
	private:
		int								port;
		string							password;
		map < string, vector<Person*> >	channels;
		map < int, Person *>			users;
		string							raw_string;
		string							hostname;
	public:
		Server();
		~Server();
		void							starter();
		void							checkInput(int fd, const string &input);
		void							makeSocketReady();
		const string					getPassword() const;	
		void							setPort(int port);
		void							setPassword(string pass);
		map< string, vector<Person*> >	&getChannels();
		vector<Person*>					getUsers();
		Person*							getUserNick(string nick);
		vector<Person*>					&getChannel(const string &channel);
		string							&getRawString();
		string							&getHostname();
		void							setRawString(string set);
		void							setHostname();
		Person*	makeUser(int fd);
		void	makeUserVanish(int fd);
		void	userHandler(const string &group, Person &user);
		void	deleteUser(const string &group, Person &user);
};

extern Server start;

#endif