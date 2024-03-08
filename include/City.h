#ifndef YAATWSM_CITY_H
#define YAATWSM_CITY_H

#include "Include.h"

class City {
    private:
        string name_;
        int id_;
        string code_;
        double demand_;
        int population_;
    public:
        City(string name, int id, string code, double demand, int population) {
            name_=name;
            id_=id;
            code_=code;
            demand_=demand;
            population_=population;
        }

        string getName() {return name_;}
        int getId() {return id_;}
        string getCode() {return code_;}
        int getDemand() {return demand_;}
        int getPopulation() {return population_;}

};

#endif //YAATWSM_CITY_H
