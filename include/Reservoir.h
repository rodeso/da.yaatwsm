#ifndef YAATWSM_RESERVOIR_H
#define YAATWSM_RESERVOIR_H


#include "Include.h"

class Reservoir {
    private:
        string name_;
        int id_;
        string code_;
        double maxDelivery_;
        string municipality_;
    public:
        Reservoir(string name, int id, string code, double maxDel, string municipality) {
            name_ =name;
            id_ = id;
            code_ = code;
            maxDelivery_ = maxDel;
            municipality_ = municipality;
        }
        string getName() {return name_;}
        int getID() {return id_;}
        string getCode() {return code_;}
        double getMaxDelivery() {return maxDelivery_;}
        string getMunicipality() {return municipality_;}
};


#endif //YAATWSM_RESERVOIR_H
