#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#define ND_ACTIVE		"You must be active to proceed "
#define A_REGIST		"Command not authorized "
#define NO_SUCH			" No such nickname or channel "
#define NO_MEM			"You are not a member of this channel => "
#define NO_OPER			" :You lack channel operator privileges"

#define ER_NICK_USED	" :This nickname is already taken"
#define ER_ALREADY_JOIN	" :Already present in the channel"
#define FIRST_USERSET	"Error: User settings must be configured first"
#define FIRST_PASSWORD	"Error: You need to provide your password first"

#define KICK_USE	"KICK command format: 'KICK <channel> <user> <reason>'"
#define JOIN_USE	"JOIN command format: 'JOIN #<channel>'"
#define NICK_USE	"NICK command format: 'NICK <nickname>'"
#define PASS_USE	"PASS command format: 'PASS <password>'"
#define PRIVMSG_USE	"PRIVMSG command format: 'PRIVMSG <recipient> <message>'"
#define USER_USE	"USER command format: 'USER <username> <hostname> <servername> <realname>'"

#define WELCOME			"Welcome to the IRC Network "
#define CORRECT_PASS	"Password has been validated successfully"
#define INCORRECT_PASS	"Password is incorrect!"

#endif
