#include "Parser.h"
#include "Builder.h"
#include <fstream>

Parser::Parser(){

}

Parser::~Parser(){

}

void Parser::parseGrammar(const char* filename){
  ifstream infile;
	string key;
	string word;
	
	infile.open(filename);
	while(infile >> word){
		if (word == "{"){
			bool first = true;
			while (word != "}"){
				infile >> word;
				string sub = word.substr(0,1);
				if(sub == "[" && first){
					key = word;
					first = false;
				}
				else{
					if (word != "}" && word != ";")
						rule.push_back(word);	
					while(word != ";"){
						if (word == "}" || word == ";")
							break;
						infile >> word;
						if (word != "}" && word != ";")
							rule.push_back(word);
					}
					rulelist.push_back(rule);
					while(!rule.empty())
						rule.pop_back();
					grammar[key] = rulelist;
				}
			}
			while(!rulelist.empty())
				rulelist.pop_back();
		}
	}
	infile.close();
}

int main(int argc, char **argv){
	ifstream infile;
	Parser the_parser;
	Builder bob;

	the_parser.parseGrammar(argv[1]);
	bob.startBuild(the_parser.grammar);
	bob.output(argv[2]);

	return 0;
}
