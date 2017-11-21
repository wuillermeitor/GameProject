#include "rapidXML\rapidxml.hpp"
#include "rapidXML\rapidxml_iterators.hpp"
#include "rapidXML\rapidxml_print.hpp"
#include "rapidXML\rapidxml_utils.hpp"
#include <iostream>
#include <sstream>
#include <string>

void main() {
	rapidxml::xml_document<> doc;
	std::ifstream file("../../res/files/BookStore.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	std::cout << "Nombre de la raiz: " << doc.first_node()->name() << "\n";
	std::cout << "Value: " << doc.first_node()->value() << "\n";

	/*rapidxml::xml_node<> *pRoot = doc.first_node();
	for (rapidxml::xml_node<> *pNode = pRoot->first_node("book"); pNode; pNode = pNode->next_sibling()) {

	}*/
}