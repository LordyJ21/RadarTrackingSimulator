#include "../include/Logger.hpp"
#include <fstream>
#include <ctime>

void Logger::log(const std::string& message)
{
    std::ofstream file("logs/events.txt", std::ios::app);

    time_t now = time(0);

    file << ctime(&now) << " : " << message << "\n";
}