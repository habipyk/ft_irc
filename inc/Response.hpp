#ifndef REPLY_HPP
#define REPLY_HPP
#include <string>
#include <Person.hpp>

enum Reply
{
	
	NONE=0,

	RPL_WELCOME = 1,
	
	RPL_YOURHOST = 2,

	RPL_CREATED = 3,
	
	RPL_MYINFO = 4,

	RPL_INFO = 371,
	RPL_NAMEREPLY = 353,
	RPL_ENDOFWHO = 315,
	RPL_ENDOFNAMES = 366,
	ERR_NOSUCHNICK = 401,
	ERR_NEEDMOREPARAMS = 461,
	ERR_NOTREGISTERED = 451,
	ERR_CHANOPRIVSNEEDED = 482,
	ERR_NONICKNAMEGIVEN = 431,
	ERR_NICKNAMEINUSE = 433,
	ERR_ALREADYREGISTRED = 462,
	ERR_PASSWDMISMATCH = 464,
	ERR_USERONCHANNEL = 443
};

enum ResponseType {
	REPLY,
	MESSAGE,
};

class Response {
	private:
		ResponseType responseType;
		string mFrom;
		string mTo;
		int mFd;
		Reply mCode;
		string mContent;
		stringstream mContentExtra;
		string generateMessage();
		string generateReply();
	public:

		Response();

		Response(const Response& response);

		~Response();

		Response& operator=(const Response& response);
		static Response create();
		static Response withCode(const Reply &reply);
		static Response createMessage();
		static Response createReply(const Reply &reply);		
		Response& from(const Person &from);
		Response& to(const Person & user);
		Response& code(const Reply &reply);
		Response& content(const string &content);
		Response& addContent(const string &content);
		void send();
};
int sendUser(const Person *origin, const Person &target, const std::string &message);

#endif