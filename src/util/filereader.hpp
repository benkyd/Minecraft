#ifndef MINECRAFT_UTIL_FILEREADER_H_
#define MINECRAFT_UTIL_FILEREADER_H_

#include <string>

class FileReader {
public:
	FileReader();

	std::string LoadTextFromFile(std::string path);

};

#endif
