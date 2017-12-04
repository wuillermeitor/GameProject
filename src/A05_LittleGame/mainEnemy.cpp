#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "../../dep/inc/rapidxml.hpp"
#include "../../dep/inc/rapidxml_utils.hpp"
#include "../../dep/inc/rapidxml_iterators.hpp"
#include "../../dep/inc/rapidxml_print.hpp"


struct enemy {
	int vitalidad;
	int damage;
	int defensa;
	int frequAt;
	int exp;
};

std::map < std::string, enemy> enemigos;

int main() {

	rapidxml::xml_document<> doc;
	std::ifstream file("../../res/files/config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<>*pRoot = doc.first_node();

	for (rapidxml::xml_node<> *pNode = pRoot->first_node("Enemy"); pNode; pNode = pNode->next_sibling()) {
		std::cout << pNode->name() << ": " << std::endl;
		for (rapidxml::xml_attribute<> *pAttr = pNode->first_attribute(); pAttr; pAttr = pAttr->next_attribute()) {
			std::cout << pAttr->name() << ": " << pAttr->value() << std::endl;
		}
		for (rapidxml::xml_node<>*pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) {
			std::cout << pNodeI->name() << ": " << pNodeI->value() << std::endl;
		}
		std::cout << std::endl;
	}



	return 0;
}