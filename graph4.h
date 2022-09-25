// Here i will try to add time as well
#include<iostream>
using namespace std;

class graph
{
protected:
    int ***matrix; // 3-D Matrix to store path and costs
    int **new_matrix;
    float ***t_time;

    int cities;
    int airlines;

    string *names;     // Name of cities
    string *air_names; // Name of airlines

public:
    graph()
    {
        cout << "Enter number of airlines " << endl;
        cin >> airlines;
        cout << "Enter number of cities " << endl;
        cin >> cities;

        names = new string[cities];
        air_names = new string[airlines];
    }

    graph(int c, int air)
    {
        cities = c;
        airlines = air;

        names = new string[cities];
        air_names = new string[airlines];
    }

    void init()
    {
        // Initialzing my matrix
        matrix = new int **[airlines]; // airline number of blocks

        t_time=new float **[airlines];

        // NEW MATRIX UPDATION
        new_matrix=new int*[cities];
        for (int i = 0; i < cities; i++)
        {
            matrix[i] = new int *[cities];
            new_matrix[i]=new int[cities];
            t_time[i]=new float *[cities];
            for (int j = 0; j < cities; j++)
            {
                matrix[i][j] = new int[cities];
                t_time[i][j]=new float[cities];
            }
        }

        // Setting matrix values to zero
        for (int i = 0; i < airlines; i++)
        {
            for (int j = 0; j < cities; j++)
            {
                
                for (int k = 0; k < cities; k++)
                {
                    matrix[i][j][k] = 0;
                    t_time[i][j][k]=0;
                    // NEW MATRIX UPDATION
                    if(i==0)
                    {
                        new_matrix[j][k]=0;
                    }
                    
                }
            }
        }

        // New updation 2
        cout << "Enter citiy names :  " << endl;
        for (int i = 0; i < cities; i++)
        {
            cout << "Enter city number " << i + 1 << " name" << endl;
            cin >> names[i];
        }
        for (int i = 0; i < airlines; i++)
        {
            cout << "Enter airline number" << i + 1 << " name" << endl;
            cin >> air_names[i];
        }
    }

    void add_edge(int air, int city1, int city2, int cost1)
    {
        matrix[air][city1][city2] = cost1;
    }

    // to add time as well
    void add_edge3(int air, int city1, int city2, int cost1,float t)
    {
        matrix[air][city1][city2] = cost1;
        t_time[air][city1][city2]=t;
    }

    void add_edge_by_name(string air, string city1, string city2, int cost1)
    {
        int air_by_int, city1_by_int, city2_by_int;
        for (int i = 0; i < airlines; i++)
        {
            if (air_names[i] == air)
            {
                air_by_int = i;
                break;
            }
        }
        for (int i = 0; i < cities; i++)
        {
            if (names[i] == city1)
            {
                city1_by_int = i;
            }
            if (names[i] == city2)
            {
                city2_by_int = i;
            }
        }
        matrix[air_by_int][city1_by_int][city2_by_int] = cost1;
    }

    // To connect cities at run time
    void add_edge2()
    {
        cout << "Following are the list of cities : ";
        for (int i = 0; i < cities; i++)
        {
            cout << i << "\t";
        }
        cout << endl;

        char stop = 'N'; // to check if user wants to add more cities or not
        do
        {
            int c1, c2, c3; // c1 and c2 are city1 and city2 and c3 is cost to go from c1 to c2
            int a1;         // a1 is the airline to go from c1 to c2

        // check for correct cities
        check:
            cout << "Enter city 1's name to connect " << endl;
            cin >> c1;
            cout << "Enter city 2's name to connect it with " << c1 << endl;
            cin >> c2;
            if (c1 < 0 || c1 > cities || c2 < 0 || c2 > cities)
            {
                cout << "Wrong input" << endl;
                goto check;
            }

        // check2 for correct airline
        check2:
            cout << "Enter the airline for it " << endl;
            cin >> a1;
            if (a1 < 0 || a1 > airlines)
            {
                cout << "Wrong airline entered " << endl;
                goto check2;
            }

            cout << "Enter distance to go from " << c1 << " to " << c2 << endl;
            cin >> c3;

            matrix[a1][c1][c2] = c3;
            cout << "Enter Y or y if you want to add more cities else enter anything else to stop !" << endl;
            cin >> stop;

        } while (stop == 'y' || stop == 'Y');
    }

    void display_matrix()
    {
        cout << "Matrix : " << endl;
        for (int a = 0; a < airlines; a++)
        {
            cout << "airline number " << a + 1 << " : " << endl;
            for (int b = 0; b < cities; b++)
            {
                for (int c = 0; c < cities; c++)
                {
                    cout << matrix[a][b][c] << "\t";
                }
                cout << endl;
            }
        }
    }

    void new_matrix_former()
    {
        for(int i=0;i<airlines;i++)
        {
            for(int j=0;j<cities;j++)
            {
                int min=9999;
                for(int k=0;k<cities;k++)
                {
                    if(matrix[i][j][k]<min && matrix[i][j][k]!=0)
                    {
                        new_matrix[j][k]=matrix[i][j][k];
                        min=matrix[i][j][k];
                    }
                }
            }
        }
    }

    void display_new_matrix()
    {
        for (int b = 0; b < cities; b++)
            {
                for (int c = 0; c < cities; c++)
                {
                    cout << new_matrix[b][c] << "\t";
                }
                cout << endl;
            }   
    }
};