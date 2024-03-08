#ifndef YAATWSM_STATION_H
#define YAATWSM_STATION_H

#include "Include.h"

class Station {
    private:
        int id_;
        string code_;
    public:
        //Constructor
        Station(int id, string code) {
            id_ = id;
            code_ = code;
        }
        //Getters
        int getId() {return id_;}
        string getCode() {return code_;}

};


#endif //YAATWSM_STATION_H
