#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <stack>
#include <list>
#include "Airport.h"
#include "Flight.h"
#include "Airline.h"
#include <set>
#include <unordered_map>
#include <unordered_set>

class Edge;

/****************** Provided structures  ********************/

class Vertex {
    std::vector<Edge> adj;  // list of outgoing edges
    bool visited;
    bool processing;
    std::vector<Vertex*> indegree;
    int num;               // auxiliary field
    int low;               // auxiliary field
    Airport airport;



public:
    Vertex(const std::string& code);

    void addToPath(Vertex* vertex);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    std::vector<Vertex*> getIndegree() const;
    void setIndegree(Vertex* v);
    const std::vector<Edge>& getAdj() const;
    const Airport& getAirport() const;
    void setAirport(const Airport& airport);

    void addEdge(Vertex* src, Vertex* dest, double w, std::string airline);
};

class Edge {
    Vertex* src;
    Vertex* dest;      // destination vertex
    double weight;         // edge weight
    std::string airline;


public:
    Edge(Vertex* src, Vertex* d, double w, std::string airline);
    Vertex* getDest() const;
    Vertex* getSrc() const;
    void setDest(Vertex* dest);
    double getWeight() const;
    std::string getAirline() const;


};

class Graph {
    std::vector<Vertex*> vertexSet;      // vertex set
    std::vector<Edge*> edgeSet;
    static void dfsVisit(Vertex* v, std::vector<std::string>& res);
    std::vector<Airline> airlines;

public:
    Edge* findEdgeByDest(const std::string dest) const;
    Vertex* findVertexByName(const std::string& name) const;
    Vertex* findVertex(const std::string& code) const;
    std::set<std::string> findVertexCity(const std::string &city) const ;
    int getNumVertex() const;
    int getNumEdges() const;
    bool addVertex(const std::string& code);
    bool addEdge(const std::string& sourc, const std::string& dest, const std::string airline, double w);
    std::vector<Vertex*> getVertexSet() const;
    std::vector<std::string> dfs();
    std::vector<std::string> dfs(const std::string& source);
    const std::set<std::string> bfs(const std::string& source) const;
    void makeUndirected();
    bool isDAG() const;

    void dfsConnectedComponents(Vertex* v, std::unordered_set<Vertex*>& visitedVertices) const;
    int countConnectedComponents() const;

    void findArticulationPointsUtil(Vertex* v, std::unordered_map<Vertex*, int>& disc,
                                           std::unordered_map<Vertex*, int>& low,
                                           std::unordered_map<Vertex*, Vertex*>& parent,
                                           std::unordered_set<Vertex*>& articulationPoints);
    void findArticulationPoints();

    std::vector<std::vector<Vertex*>> findFlightsWithFilters(const std::string& source, const std::string& destination, const std::vector<std::string>& preferredAirlines, bool minimizeAirlineChanges);


    std::vector<std::vector<Vertex*>> findAllFlights(const std::string& source, const std::string& destination);
    void findAllFlightsUtil(Vertex* current, Vertex* destination, std::vector<Vertex*>& path, std::vector<std::vector<Vertex*>>& allPaths, std::unordered_set<Vertex*>& visited);
};

#endif
