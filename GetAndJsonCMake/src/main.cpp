#include <iostream>
#include <string>

#include <cpr/cpr.h>
#include "../include/json.hpp"

using json = nlohmann::json;


int main()
{
    setlocale(LC_ALL, "Russian");
    
    cpr::Response r = cpr::Get(cpr::Url{ "https://kav-api.kovalev.team/servodrive/lastActualData?servoDriveId=1" });

    // Статус код
    std::cout << "Status code: " << r.status_code << '\n';
    
    // Заголовки, если нужны
    //std::cout << "Header:\n";
    //for (const std::pair<const std::basic_string<char>, std::basic_string<char>>& kv : r.header) {
    //    std::cout << '\t' << kv.first << ':' << kv.second << '\n';
    //}
    
    // Парсим JSON из запроса и выводим
    json res_text = json::parse(r.text);
    /// Перевод из cp1251 в utf8 оставлю самим делать
    /// Запрос с таймаутом заворачивается легко в цикл
    //std::cout << res_text["data"][0][1][0][1].get<std::string>() << std::endl;
    //std::cout << res_text[0]["actPhaseU"].get<std::string>() << std::endl;

    for (auto& [key, value] : res_text[0].items())
    {
      std::cout << key << ": " << value << std::endl;
    }


	system("pause>nul");
	return 0;
}
