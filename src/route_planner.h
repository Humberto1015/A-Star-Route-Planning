#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "route_model.h"


class RoutePlanner {
  public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    // Add public variables or methods declarations here.
    float GetDistance() const {return distance;}
    void AStarSearch();

    // The following methods have been made public so we can test them individually.
    void AddNeighbors(RouteModel::Node *current_node);
    float CalculateHValue(RouteModel::Node const *node);
    std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *);
    RouteModel::Node *NextNode();

  private:
    // Add private variables or methods declarations here.
    //std::vector<RouteModel::Node*> open_list;
  	// min heap
  	struct cmp {
      	bool operator()(RouteModel::Node const *n1, RouteModel::Node const *n2) {
          	return (n1->g_value + n1->h_value) > (n2->g_value + n2->h_value);
        }
    };
  	std::priority_queue<RouteModel::Node*, std::vector<RouteModel::Node*>, cmp> min_heap;
    RouteModel::Node *start_node;
    RouteModel::Node *end_node;

    float distance = 0.0f;
    RouteModel &m_Model;
};

#endif