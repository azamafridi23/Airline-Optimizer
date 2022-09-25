#include "graph4.h"
#include "queue3.h"
#include "linked_list2.h"
#include "linked_list3.h"
#include <climits>
#include <limits.h>
#include <queue>


class flight : public graph
{
private:
    linked_list possible_paths;
    linked_list possible_airlines;
    linked_list2 cost;
    linked_list3 possible_time; // make a float ll
    int number_of_paths;

    // UPDATION
    vector<int> *best_paths;
    vector<int> *best_airlines;
    vector<float> *best_time;
    int *best_cost;

public:
    flight()
    {
        number_of_paths = 0;
        cout<<"********  Welcome To Flight Optimizer  ********"<<endl;
        cout<<"Provided different airlines their routes,cost and time. We will find out the cheapest possible route for you "<<endl;
        cout<<"By using the best possible use of Data Structures And Algorithms \n"<<endl;
    }

    // To calculate best airline between two cities
    int best_airline_between_two(int city1, int city2)
    {
        int best = INT_MAX;
        int air1;

        for (int i = 0; i < airlines; i++)
        {
            if (matrix[i][city1][city2] < best && matrix[i][city1][city2] != 0)
            {
                best = matrix[i][city1][city2];
                air1 = i;
            }
        }
        return air1;
    }

    // To check if a particular city is already visited in a path or not
    int is_not_visited(int city1, vector<int> &path1)
    {
        for (int i = 0; i < path1.size(); i++)
        {
            if (path1[i] == city1)
            {
                return 0;
            }
        }
        return 1;
    }

    void find_paths2(int start, int goal)
    {
        int to_append_in_paths = 0;
        int to_append_in_cost = 0;
        int counter1 = 0; // will check if loop executed for not. if not this means there is no path
        // queue2 q;
        // queue<vector<int>> q;
        queue1 q2;
        vector<int> path;
        path.push_back(start);
        // q.enqueue(path);
        // q.push(path);
        q2.enqueue(path);

        // cout << " FOR AIRLINE " << i << endl;

        while (!q2.empty())
        {
            // path = q.dequeue();
            path = q2.dequeue();
            // q.pop();
            int last = path[path.size() - 1];

            if (last == goal)
            {
                possible_paths.insert(path);
                // NEW UPDATION
                // possible_paths.head->insert(possible_paths.head, path);

                counter1++;
                number_of_paths++;
                // p_paths[to_append_in_paths] = path;
                int size = path.size();
                int count = 0;
                vector<int> tempv;
                vector<float> temp_time;
                while (size - 1 > count)
                {
                    int a = path[count];
                    int b = path[count + 1];
                    int cheapest_airline = best_airline_between_two(a, b);
                    // int cost_by_two_cities = matrix[cheapest_airline][a][b];
                    // cost.insert(cost.gethead()->getdata() + cost_by_two_cities);
                    tempv.push_back(best_airline_between_two(a, b));
                    // temp_time.push_back(t_time[0][0][0]);
                    // cost[to_append_in_cost] = cost[to_append_in_cost] + cost_by_two_cities;
                    // best_airlines[to_append_in_paths].push_back(best_airline_between_two(a, b)); // can also write .pushback(cheapest_airline)
                    count++;
                }
                // NEW UPDATION
                possible_airlines.insert(tempv);
                // resetting tempv
                tempv.clear();

                to_append_in_paths = to_append_in_paths + 1;
                to_append_in_cost = to_append_in_cost + 1;


            }
            for (int j = 0; j < cities; j++)
            {
                if (new_matrix[last][j] != 0 && is_not_visited(j, path))
                {
                    vector<int> newpath(path); // new path made from prev path;
                    newpath.push_back(j);
                    // q.enqueue(newpath);
                    q2.enqueue(newpath);
                }
            }
        }
        if (counter1 == 0)
        {
            cout << "Sorry No Path Exists " << endl;
        }
        cout << "------------------------------------" << endl;
        node *temp = possible_paths.gethead();
        best_paths = new vector<int>[number_of_paths];
        best_airlines = new vector<int>[number_of_paths];

        best_cost = new int[number_of_paths];

        int z = 0;
        while (temp != NULL)
        {
            int count = 0;
            int c_cost = 0; // to compute cost and store in best_cost
            vector<int> myv = temp->getdata();
            best_paths[z] = myv;
            int size_of_each_path = myv.size();
            while (count < size_of_each_path - 1)
            {
                int a = myv[count];
                int b = myv[count + 1];
                best_airlines[z].push_back(best_airline_between_two(a, b));
                c_cost = c_cost + matrix[best_airline_between_two(a, b)][a][b];
                count++;
            }
            best_cost[z] = c_cost;
            z++;
            temp = temp->getnext();
        }
        // cout << "z = " << z << endl;
        // cout << "size of best_paths = " << best_paths->size() << endl;
    }

    void display_paths(int start, int goal)
    {
        // NEW UPDATION
        linked_list possible_paths;
        linked_list possible_airlines;
        linked_list2 cost;
        linked_list2 possible_time; // make a float ll
        int number_of_paths;
        vector<int> *best_paths; // Array of vectors
        vector<int> *best_airlines;
        vector<float> *best_time;
        int *best_cost;


        int to_append_in_paths = 0;
        int to_append_in_cost = 0;
        int counter1 = 0; // will check if loop executed for not. if not this means there is no path
        for (int i = 0; i < airlines; i++)
        {
            queue1 q2;  // N
            queue<vector<int>> q;
            vector<int> path;
            path.push_back(start);
            // q.enqueue(path);
            // q.push(path); // N
            q2.enqueue(path); // N
            cout << " FOR AIRLINE " << i << endl;
            cout<<"FOR AIRLINE "<<air_names[i]<<endl;

            while (!q2.empty()) //N
            {
                // path = q.dequeue();
                // path = q.front(); // N
                path = q2.dequeue(); //N
                // q.pop(); // N
                int last = path[path.size() - 1];

                if (last == goal)
                {
                    possible_paths.insert(path);
                    // NEW UPDATION
                    // possible_paths.head->insert(possible_paths.head, path);

                    counter1++;
                    number_of_paths++;
                    // p_paths[to_append_in_paths] = path;
                    int size = path.size();
                    int count = 0;
                    vector<int> tempv;
                    while (size - 1 > count)
                    {
                        int a = path[count];
                        int b = path[count + 1];
                        int cheapest_airline = best_airline_between_two(a, b);
                        int cost_by_two_cities = matrix[cheapest_airline][a][b];
                        // cost.insert(cost.gethead()->getdata() + cost_by_two_cities);
                        tempv.push_back(best_airline_between_two(a, b));
                        // cost[to_append_in_cost] = cost[to_append_in_cost] + cost_by_two_cities;
                        // best_airlines[to_append_in_paths].push_back(best_airline_between_two(a, b)); // can also write .pushback(cheapest_airline)
                        count++;
                    }
                    // NEW UPDATION
                    possible_airlines.insert(tempv);
                    // resetting tempv
                    tempv.clear();

                    to_append_in_paths = to_append_in_paths + 1;
                    to_append_in_cost = to_append_in_cost + 1;

                    cout << "Path found = " << endl;
                    int current_cost = 0; // I made this so that i can compute cost of current airline and paths in down loop bcz i dont want to disturb the cost variable which has cost of best path
                    // for (int k = 0; k < path.size(); k++)
                    // {
                    //     int a = path[k];
                    //     int b = path[k + 1];
                    //     cout << path[k] << "\t";
                    //     if (k != path.size() - 1)
                    //     {
                    //         int c = matrix[i][a][b];
                    //         current_cost = current_cost + matrix[i][a][b];
                    //     }
                    // }

                    // New updation 2
                    cout<<endl;
                    int current_cost2 = 0;
                    for (int k = 0; k < path.size(); k++)
                    {
                        int a = path[k];
                        int b = path[k + 1];
                        cout << names[a] << " ----> ";
                        if (k != path.size() - 1)
                        {
                            int c = matrix[i][a][b]; // for debugging
                            current_cost2 = current_cost2 + matrix[i][a][b];
                        }
                    }
                    cout << endl;
                    cout << "At cost " << current_cost2 << endl;
                    cout << "-------------------------------------\n";
                }
                for (int j = 0; j < cities; j++)
                {
                    if (matrix[i][last][j] != 0 && is_not_visited(j, path))
                    {
                        vector<int> newpath(path); // new path made from prev path;
                        newpath.push_back(j);
                        // q.enqueue(newpath);
                        // q.push(newpath); // N
                        q2.enqueue(newpath);
                    }
                }
            }
            if (counter1 == 0)
            {
                cout << "Sorry No Path Exists " << endl;
            }
            cout << "------------------------------------" << endl;
        }
        node *temp = possible_paths.gethead();
        best_paths = new vector<int>[number_of_paths];
        best_airlines = new vector<int>[number_of_paths];

        int z = 0;
        while (temp != NULL)
        {
            int count = 0;
            vector<int> myv = temp->getdata();
            best_paths[z] = myv;
            int size_of_each_path = myv.size();
            while (count < size_of_each_path - 1)
            {
                int a = myv[count];
                int b = myv[count + 1];
                best_airlines[z].push_back(best_airline_between_two(a, b));
                count++;
            }
            z++;
            temp = temp->getnext();
        }
        // cout << "z = " << z << endl;
        // cout << "size of best_paths = " << best_paths->size() << endl;
    }

    void display_best_paths()
    {
        cout << "************************************************************\n";
        cout << "The best paths, airlines with their specified cost are mentioned below : " << endl;

        int counter2 = 0; // will check if loop executed for not. if not this means there is no path
        cout << "************************************************************" << endl;

        cout << "Try by azam = " << endl;

        for (int j = 0; j < number_of_paths; j++)
        {
            cout << "Path = " << endl;
            for (int m = 0; m < best_paths[j].size(); m++)
            {
                cout << best_paths[j][m] << "\t";
            }
            cout << endl;
            cout << "Airline = " << endl;
            for (int n = 0; n < best_airlines[j].size(); n++)
            {
                cout << best_airlines[j][n] << "\t";
            }
            cout << endl;
            cout << "cost = " << endl;
            cout << best_cost[j] << endl;
        }
    }

    // to return min in a array
    int min(int arr[], int n)
    {
        int temp = arr[0];
        for (int i = 0; i < n; i++)
        {
            if (temp > arr[i])
            {
                temp = arr[i];
            }
        }
        return temp;
    }


    void comparator()
    {
        int minimum_cost = min(best_cost, number_of_paths);
        cout << "After comparison the best possible paths and airlines are = " << endl;
        for (int i = 0; i < number_of_paths; i++)
        {
            if (best_cost[i] <= minimum_cost)
            {
                for (int m = 0; m < best_paths[i].size(); m++)
                {
                    cout << best_paths[i][m] << "\t";
                }
                cout << endl;
                cout << "Airline = " << endl;
                for (int n = 0; n < best_airlines[i].size(); n++)
                {
                    cout << best_airlines[i][n] << "\t";
                }
                cout << endl;
                cout << "cost = " << endl;
                cout << best_cost[i] << endl;
            }
        }
    }

    void comparator2()
    {

        int minimum_cost = min(best_cost, number_of_paths);
        int counterx=0; // to check if loop executed or not
        cout << "After Comparisons and calculations. Following are the cheapest routes and airline you can take to reach your destination = " << endl;
        for (int i = 0; i < number_of_paths; i++)
        {
            float temp_time = 0;
            if (best_cost[i] <= minimum_cost)
            {
                for (int m = 0; m < best_paths[i].size(); m++)
                {
                    // cout << best_paths[i][m] << "\t";
                    cout << names[best_paths[i][m]] << " ----> ";
                    counterx++;
                }
                cout << endl;
                cout << "Airline = " << endl;
                for (int n = 0; n < best_airlines[i].size(); n++)
                {
                    // cout << best_airlines[i][n] << "\t";
                    cout << " --- " << air_names[best_airlines[i][n]] << "--- ";
                }
                cout << endl;
                cout << "cost = " << endl;
                cout << best_cost[i] << endl;
                cout << "Time = " << endl;
                for (int m = 0; m < best_paths[i].size(); m++)
                {
                    if (m != best_paths[i].size() - 1)
                    {
                        temp_time = temp_time + t_time[best_airlines[i][m]][best_paths[i][m]][best_paths[i][m + 1]];
                    }
                }
                cout << temp_time << endl;
            }
        }
        if(counterx==0)
        {
            cout<<"Unfortunately no path exists !"<<endl;
        }
    }
};