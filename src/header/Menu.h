#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <set>
#include <unordered_map>
#include "Graph.h"

class Menu {
public:

    static void displayMenu(Graph ap);
    static void airportInfoMenu(Graph ap);
    static void statsMenu(Graph ap);

private:

    static void printAvailableAirports(Graph ap);
    static void printAvailableFlights(Graph ap);
    static void countFlightsOutOfAirport(Graph ap);
    static void flightsPerCityPerAirline(Graph ap);
    static void flightsPerAirline(Graph ap);
    static void countCountriesForAirport(Graph ap);
    static void countCountriesForCity(Graph ap);
    static void printNumDestinationsForAirport(Graph ap);
    static void ranking(Graph ap);
    static void numReachableDestinations(Graph ap);
    int countCities(Graph ap, std::set<std::string> visited);
    int countCountries(Graph ap, std::set<std::string> visited);
    static void findMaxStopsTrip(Graph& graph);
    static void bestFlightOption(Graph ap);
    static void searchFlightsWithFilters(Graph ap);
    static std::string getAirlineName(const std::string& airlineCode);

    // AUX

    static std::set<std::string> findClosestAirports(Graph ap, double lat, double lon);
    static std::string uniformizer(std::string input);

};

#endif