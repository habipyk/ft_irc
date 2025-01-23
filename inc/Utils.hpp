#ifndef	UTILS_HPP
#define	UTILS_HPP

#include <Server.hpp>
#include <Message.hpp>
#include <DefineMod.hpp>
#include <Global.hpp>
#include <DefineMod.hpp>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[0m"

void	modeHandler(vector<Person *> &channel, string group, string nickname);
void	groupMsg(Person & user, const string n_channel, const string msg);
void	printerCl(string msg, Person &server);
void	printerSrv(string msg);
bool	searchCh(string target, Person &from);
bool	searchCh(vector <Person *> group, string name);
bool	Compare(const string &test, const string &aim, int enter);
string	Visualizer(vector<Person *>& persons);
string	getColor(int fd);
string	getTime();



#endif