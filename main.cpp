#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>

int main() {
  std::multimap<int, std::string> list;
  std::multimap<int, std::string>::iterator it;
  std::time_t seconds = std::time(nullptr);
  std::tm local = *std::localtime(&seconds);
  std::string command;
  std::string name;

  do {
    std::cout << "Enter name: " << std::endl
              << "for exit enter <end>" << std::endl;
    std::cin >> command;
    if (command == "end")
      break;
    else {
      name = command;
      std::cout << "Enter Date of Birth < yyyy/mm/dd > :" << std::endl;
      std::cin >> std::get_time(&local, "%Y/%m/%d");
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Enter error! Repeat." << std::endl;
        continue;
      }
      char buffer[5];
      char buffer_2[6];
      strftime(buffer, 5, "%m%d", &local);
      strftime(buffer_2, 6, "%m/%d", &local);
      int date = std::stoi(buffer);
      name = name + ": " + buffer_2;
      list.emplace(date, name);
    }
  } while (true);

  tm local_l = *std::localtime(&seconds);
  char buffer_3[5];
  strftime(buffer_3, 5, "%m%d", &local_l);
  int dateNow = std::stoi(buffer_3);
  name = "noname";
  list.emplace(dateNow, name);

  std::cout << "===================================================" << std::endl;
  bool flag = false;
  for (it = list.find(dateNow); it != list.end(); it++) {
    if (it->first == dateNow && it->second != "noname") {
      std::cout << "Today - " << it->second << std::endl;
      flag = true;
    }
  }
  if (!flag) {
    it = list.find(dateNow);
    ++it;
    if (it != list.end()) {
      std::cout << it->second << std::endl;
    } else {
      it = list.begin();
      std::cout << it->second << std::endl;
    }
  }
  std::cout << "===================================================" << std::endl;
  return 0;
}
