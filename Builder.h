#ifndef BUILDER_H_
#define BUILDER_H_

#include "Parser.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Builder{
public:
  Builder();
	~Builder();
	void startBuild(map<string, vector<list<string> > > grammar);
	void output(const char* filename);
	list<string> build(string word, map<string, vector<list<string> > > _map, map<string, vector<list<string> > >::iterator it, list<string>& words);
private:
	vector<list<string> > full;
};
#endif
