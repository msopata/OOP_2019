#pragma once
#include <string>

class TextWrapper{
public:
    TextWrapper();
    TextWrapper( int columnsNumber, std::string text );

    int columns() const;

    std::string text() const;

    std::string wrap();




private:
    int columns_Number{ 1 };
    std::string s_text{""};

};
