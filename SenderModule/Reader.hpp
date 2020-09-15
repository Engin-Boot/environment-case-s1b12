#pragma once

class Reader
{
    public:
        virtual std::string fetch_current_row() = 0;
        virtual bool good() = 0;
        virtual ~Reader()
        { 
        }
}; 