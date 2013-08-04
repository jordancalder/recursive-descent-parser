#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

class Parser{
  friend class Builder;
public:
	Parser();
	~Parser();
	//void output(const char* filename, vector<Xml> list);
	void parseGrammar(const char* filename);
	map<string, vector<list<string> > > grammar;
private:
	vector<list<string> > rulelist;
	list<string> rule;
};

#endif
