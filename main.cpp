#include <iostream>
#include <fstream>

int main() {
  std::ifstream textFile;
  size_t buffer_size = 1;
  char *buffer = new char[buffer_size];

  std::string path;
  std::getline(std::cin, path);
  
  textFile.open(path, std::ios::binary);
  
  if (textFile.is_open()) {
    while (!textFile.eof()) {
      textFile.read(buffer, buffer_size);
      size_t count = textFile.gcount();
      if (!count) 
          break;
      std::cout << buffer;
    } 
  } else {
    std::cout << "Path \"" << path << "\" Incorrect!";
  }

  delete[] buffer;
  textFile.close();
}

/*
Разработайте простейший просмотрщик текстовых файлов. В начале программы пользователь вводит путь к текстовому файлу, который требуется открыть и просмотреть. 
Внутренности файла необходимо вывести в стандартный вывод. 
Программа должна работать для любых текстовых файлов в формате TXT, но вы можете создать и свой отдельный файл для теста. 
Главное, чтобы файл был англоязычным, дабы избежать проблем с кодировками.
*/