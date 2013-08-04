#include "Builder.h"
#include <fstream>

Builder::Builder(){

}

Builder::~Builder(){

}

void Builder::startBuild(map<string, vector<list<string> > > grammar){
  srand(time(0));
	list<string> random_sentence;
	list<string> words;
	map<string, vector<list<string> > >::iterator mapIter;
	
	mapIter = grammar.find("[start]");
	vector<list<string> > start = mapIter->second;
	list<string> starting = start[0];
	list<string>::iterator it;
	for(it = starting.begin();it != starting.end(); ++it){
		string word = *it;
		random_sentence = build(word, grammar, mapIter, words);
	}
	full.push_back(random_sentence);
}

list<string> Builder::build(string word, map<string, vector<list<string> > > _map, map<string, vector<list<string> > >::iterator it, list<string>& words){
	cout << "building... " << word << endl;
	if (word.substr(0,1) == "["){
		it = _map.find(word);
		vector<list<string> > rules = it->second;
		int y = rules.size()-1;
		if(y == 0)
			y = 1;
		list<string> the_rule = rules[rand() % y];
		list<string>::iterator ruleit;
		for(ruleit = the_rule.begin(); ruleit != the_rule.end();++ruleit){
			string check_rule = *ruleit;
			build(check_rule, _map, it, words);
		}
		return words;
	}
	else{
		words.push_back(word);
		return words;
	}
}

void Builder::output(const char* filename){
	ofstream outfile;
	outfile.open(filename);
	list<string>::iterator getit;
	for(size_t i = 0; i != full.size(); i++){
		list<string> get = full[i];
		for(getit = get.begin(); getit != get.end();++getit){
			outfile << *getit << " ";	
		}
	}
	outfile.close();
}
