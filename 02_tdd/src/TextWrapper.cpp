#include "TextWrapper.h"


TextWrapper::TextWrapper(int columnsNumber, std::string text) :
    columns_Number(columnsNumber),
    s_text(text)
{ }

TextWrapper::TextWrapper()
{ }


int TextWrapper::columns() const {
    return columns_Number;
}


std::string TextWrapper::text() const {
    return s_text;
}

std::string TextWrapper::wrap(){
    std::string textBuffer;
}