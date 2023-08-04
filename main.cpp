#include <iostream>
#include <fstream>


#define nl "\n"
#define sz(m) (int)m.size()

using namespace std;

class plan {
public:
    char plan_id[10], country[20], captin[20], assistent[20], time_out[60];
    int count_passenger;
};

class passanger {
public:
    char id_pass[10], name_pass[20], id_pla[10], city[20];
    int price;
};

class crew {
public:
    char emp_name[20], emp_id[10], plane_id[20];
    int sale;
};

void add_plans_information() {
    plan p;
    ofstream in_plan("addplan.txt", ios::out | ios::app);
    cout << "Please enter the ID of the plane : ";
    cin >> p.plan_id;
    cout << "Please enter the name of the country : ";
    cin >> p.country;
    cout << "Please enter the name of the captain : ";
    cin >> p.captin;
    cout << "Please enter the name of the assistant captain : ";
    cin >> p.assistent;
    cout << "Please enter the number of passengers : ";
    cin >> p.count_passenger;
    cout << "Please enter the flight departure time as (day_month_year||hour:minute) without any space : ";
    cin >> p.time_out;
    in_plan.write((char *) &p, sizeof(p));
    in_plan.close();
}

void editspace(int num, string &s) {
    int x = num - sz(s);
    for (int i = 0; i < x / 2; i++)cout << " ";
    cout << s;
    for (int i = x / 2; i < x; i++)cout << " ";
}

void view_plan() {
    plan p1;
    ifstream viweplan("addplan.txt", ios::in);
    viweplan.read((char *) &p1, sizeof(p1));
    cout
            << "---------------------------------------------------------------------------------------------------------------------------\n";
    cout
            << "Plane ID   ::    Country    ::    Captain    ::    Assistant captain    ::    Num_passenger    ::   Time of departure      \n";
    cout
            << "---------------------------------------------------------------------------------------------------------------------------\n";
    while (!viweplan.eof()) {
        string s = p1.plan_id, m = "Plane ID   ";
        editspace(sz(m), s);
        cout << "::";
        s = p1.country, m = "    Country    ";
        editspace(sz(m), s);
        cout << "::";
        s = p1.captin, m = "    Captain    ";
        editspace(sz(m), s);
        cout << "::";
        s = p1.assistent, m = "    Assistant captain    ";
        editspace(sz(m), s);
        cout << "::";
        s = to_string(p1.count_passenger), m = "    Num_passenger    ";
        editspace(sz(m), s);
        cout << "::";
        s = p1.time_out, m = "   Time of departure      ";
        editspace(sz(m), s);
        cout << endl;
        cout
                << "---------------------------------------------------------------------------------------------------------------------------\n";

        viweplan.read((char *) &p1, sizeof(p1));

    }
    viweplan.close();
}

void search_plan() {
    plan p1;
    ifstream viweplan("addplan.txt", ios::in);
    viweplan.read((char *) &p1, sizeof(p1));
    bool check = true;
    cout << "\n\n1-Search by Plane ID.\n";
    cout << "2-Search by Country.\n";
    cout << "3-Search by Captain name.\n";
    cout << "4-Search by Assistant captain name.\n";
    cout << "5-Search by number of passengers.\n";
    cout << "6-Search by Time of departure\n";
    cout << "7-Back to last menu.\n";
    cout << "\n\nEnter your choice : ......";
    int n;
    cin >> n;
    if (n == 7)return;
    while (n > 6 || n < 0) {
        cout << " Your choice is not clear, please re-choice :.....";
        cin >> n;
    }
    string key;
    cout << endl;
    switch (n) {
        case 1:
            cout << "Enter the plane ID you want to search for :...";
            break;
        case 2:
            cout << "Enter the country you want to search for :...";
            break;
        case 3:
            cout << "Enter the captain's name you want to search for :...";
            break;
        case 4:
            cout << "Enter the Assistant captain name you want to search for :...";
            break;
        case 5:
            cout << "Enter the number of passengers you want to search for :...";
            break;
        case 6:
            cout << "Enter the Time of departure you want to search for :...";
            break;

    }
    cin >> key;
    while (!viweplan.eof()) {
        if ((n == 1 && key == p1.plan_id) || (n == 2 && key == p1.country) || (n == 3 && key == p1.captin) ||
            (n == 4 && key == p1.assistent) ||
            (n == 5 && key == to_string(p1.count_passenger) || (n == 6 && key == p1.time_out))) {
            if (check) {
                cout
                        << "\n\n---------------------------------------------------------------------------------------------------------------------------\n";
                cout
                        << "Plane ID   ::    Country    ::    Captain    ::    Assistant captain    ::    Num_passenger    ::   Time of departure      \n";
                cout
                        << "---------------------------------------------------------------------------------------------------------------------------\n";
                check = false;
            }

            string s = p1.plan_id, m = "Plane ID   ";
            editspace(sz(m), s);
            cout << "::";
            s = p1.country, m = "    Country    ";
            editspace(sz(m), s);
            cout << "::";
            s = p1.captin, m = "    Captain    ";
            editspace(sz(m), s);
            cout << "::";
            s = p1.assistent, m = "    Assistant captain    ";
            editspace(sz(m), s);
            cout << "::";
            s = to_string(p1.count_passenger), m = "    Num_passenger    ";
            editspace(sz(m), s);
            cout << "::";
            s = p1.time_out, m = "   Time of departure      ";
            editspace(sz(m), s);
            cout << endl;
            cout
                    << "---------------------------------------------------------------------------------------------------------------------------\n";

        }
        viweplan.read((char *) &p1, sizeof(p1));

    }
    if (check) {
        cout << "\n\n******************************\n";
        cout << "** This data does not exist **\n";
        cout << "******************************\n";
        cout << "\n\n";
    }
    viweplan.close();
}

void delete_plan_information() {
    plan p3;
    cout << "Please enter the id of the plane whose data you want to delete : ....";
    string s;
    cin >> s;
    cout << "\n\n";
    fstream old("addplan.txt", ios::in | ios::out | ios::app);
    ofstream neew("current.txt", ios::out | ios::app);
    old.read((char *) &p3, sizeof(p3));
    bool check = true;
    while (!old.eof()) {
        if (p3.plan_id != s) {
            neew.write((char *) &p3, sizeof(p3));
        } else check = false;
        old.read((char *) &p3, sizeof(p3));
    }
    old.close();
    neew.close();
    if (check) {
        cout << "******************************\n";
        cout << "** This data does not exist **\n";
        cout << "******************************\n";
        cout << "\n\n";

    }
    remove("addplan.txt");
    rename("current.txt", "addplan.txt");

}

void editplantable() {
    cout << "Please enter the id of the plane whose data you want to modify :  ....";
    string s;
    cin >> s;
    plan p6;
    fstream ino("addplan.txt", ios::in | ios::out);
    ino.read((char *) &p6, sizeof(p6));
    bool check = true;
    while (!ino.eof()) {
        if (s == p6.plan_id) {
            cout << endl << endl;
            cout << "\n1-Modify the captain's name.";
            cout << "\n2-Modify the Assistant captain's name.";
            cout << "\n3-Modify the passenger's number.";
            cout << "\n4-Modify the flight departure time.";
            cout << "\n5-Modify the country.";
            cout << "\n6-Back to last menu.";
            cout << "\n\nEnter your choice : ......";
            int n;
            cin >> n;
            if (n == 6)return;
            while (n > 5 || n < 0) {
                cout << " Your choice is not clear, please re-choice :.....";
                cin >> n;
            }
            check = false;
            if (n == 1) {
                cout << "Enter the new captain's name :....";
                cin >> p6.captin;
            } else if (n == 2) {
                cout << "Enter the new Assistant captain's name :....";
                cin >> p6.assistent;
            } else if (n == 3) {
                cout << "Enter the new passenger's number :....";
                cin >> p6.count_passenger;
            } else if (n == 4) {
                cout << "Enter the new flight departure time :....";
                cin >> p6.time_out;
            } else if (n == 5) {
                cout << "Enter the new country :....";
                cin >> p6.country;
            }

            ino.seekp((int) ino.tellg() - sizeof(p6), ios::beg);
            ino.write((char *) &p6, sizeof(p6));
        }
        ino.read((char *) &p6, sizeof(p6));
    }
    if (check) {
        cout << "******************************\n";
        cout << "** This data does not exist **\n";
        cout << "******************************\n";
        cout << "\n\n";
    }


}

void add_passanger_information() {
    passanger p1;
    fstream pas1("Air_plane.txt", ios::out | ios::app);
    cout << "Enter ID_passanger : ";
    cin >> p1.id_pass;
    cout << "Enter Name : ";
    cin >> p1.name_pass;
    cout << "Enter ID_plane : ";
    cin >> p1.id_pla;
    cout << "Enter City : ";
    cin >> p1.city;
    cout << "Enter Price : ";
    cin >> p1.price;
    pas1.write((char *) &p1, sizeof(p1));
    pas1.close();
}

void view_passenger() {
    passanger p2;
    fstream send;
    send.open("Air_plane.txt", ios::in);
    if (send.is_open()) {
        cout << "-----------------------------------------------------------------------------------" << nl;
        cout << "Passenger ID   ::   Passenger's name   ::   Plane ID   ::   Country   ::   Price   " << nl;
        cout << "-----------------------------------------------------------------------------------" << nl;
        send.read((char *) &p2, sizeof(p2));
        while (!send.eof()) {
            string s = p2.id_pass, m = "Passenger ID   ";
            editspace(sz(m), s);
            cout << "::";
            s = p2.name_pass, m = "   Passenger's name   ";
            editspace(sz(m), s);
            cout << "::";
            s = p2.id_pla, m = "   Plane ID   ";
            editspace(sz(m), s);
            cout << "::";
            s = p2.city, m = "   Country   ";
            editspace(sz(m), s);
            cout << "::";
            s = to_string(p2.price), m = "   Price   ";
            editspace(sz(m), s);
            cout << "\n";
            cout << "-----------------------------------------------------------------------------------" << nl;
            send.read((char *) &p2, sizeof(p2));
        }
        send.close();
    } else
        cout << "Can not open the specified file" << nl;
}

void search_passenger() {
    passanger p2;
    fstream send;
    send.open("Air_plane.txt", ios::in);
    if (send.is_open()) {
        send.read((char *) &p2, sizeof(p2));
        bool check = true;
        cout << "\n\n1-Search by Passenger ID.\n";
        cout << "2-Search by Passenger's name.\n";
        cout << "3-Search by Plane ID.\n";
        cout << "4-Search by Country.\n";
        cout << "5-Search by Price.\n";
        cout << "6-Back to last menu.\n";
        cout << "\n\nEnter your choice : ......";
        int n;
        cin >> n;
        if (n == 6)return;
        while (n > 5 || n < 0) {
            cout << " Your choice is not clear, please re-choice :.....";
            cin >> n;
        }
        cout << "\n";
        switch (n) {
            case 1:
                cout << "Enter the Passenger ID you want to search for :...";
                break;
            case 2:
                cout << "Enter the Passenger's name you want to search for :...";
                break;
            case 3:
                cout << "Enter the plane ID you want to search for :...";
                break;
            case 4:
                cout << "Enter the Country you want to search for :...";
                break;
            case 5:
                cout << "Enter the Price you want to search for :...";
                break;
        }
        string key;
        cin >> key;
        while (!send.eof()) {
            if ((n == 1 && key == p2.id_pass) || (n == 2 && key == p2.name_pass) || (n == 3 && key == p2.id_pla) ||
                (n == 4 && key == p2.city) || (n == 5 && key == to_string(p2.price))) {
                if (check) {
                    cout << "-----------------------------------------------------------------------------------" << nl;
                    cout << "Passenger ID   ::   Passenger's name   ::   Plane ID   ::   Country   ::   Price   " << nl;
                    cout << "-----------------------------------------------------------------------------------" << nl;
                    check = false;
                }
                string s = p2.id_pass, m = "Passenger ID   ";
                editspace(sz(m), s);
                cout << "::";
                s = p2.name_pass, m = "   Passenger's name   ";
                editspace(sz(m), s);
                cout << "::";
                s = p2.id_pla, m = "   Plane ID   ";
                editspace(sz(m), s);
                cout << "::";
                s = p2.city, m = "   Country   ";
                editspace(sz(m), s);
                cout << "::";
                s = to_string(p2.price), m = "   Price   ";
                editspace(sz(m), s);
                cout << "\n";
                cout << "-----------------------------------------------------------------------------------" << nl;
            }
            send.read((char *) &p2, sizeof(p2));
        }
        if (check) {
            cout << "\n\n******************************\n";
            cout << "** This data does not exist **\n";
            cout << "******************************\n";
            cout << "\n\n";
        }
        send.close();
    } else
        cout << "Can not open the specified file" << nl;
}

void delete_passenger_information() {
    string s;
    cout << "\nEnter ID_pass to delete : ";
    cin >> s;
    bool found = true;
    passanger p5;
    ifstream in("Air_plane.txt", ios::in);
    ofstream out("Temp.txt", ios::out);
    if (in.is_open()) {
        in.read((char *) &p5, sizeof(p5));
        while (!in.eof()) {
            if (s != p5.id_pass) {
                out.write((char *) &p5, sizeof(p5));
            } else found = false;
            in.read((char *) &p5, sizeof(p5));
        }
        if (found) {
            cout << "\n\n******************************\n";
            cout << "** This data does not exist **\n";
            cout << "******************************\n";
            cout << "\n\n";
        }

        in.close();
        out.close();
        remove("Air_plane.txt");
        rename("Temp.txt", "Air_plane.txt");
    } else
        cout << "Can not open the specified file" << nl;

}

void editpassengertable() {

    cout << "\nPlease enter the id of the passenger whose data you want to modify :  ....";
    string s;
    cin >> s;
    bool found = false;
    passanger p4;
    fstream in;
    in.open("Air_plane.txt", ios::in | ios::out);
    if (in.is_open()) {
        in.read((char *) &p4, sizeof(p4));
        while (!in.eof()) {
            if (s == p4.id_pass) {
                cout << endl << endl;
                cout << "\n1-Modify the passenger ID.";
                cout << "\n2-Modify the passenger's name.";
                cout << "\n3-Modify the plane ID.";
                cout << "\n4-Modify the country.";
                cout << "\n5-Modify the price.";
                cout << "\n6-Back to last menu.";
                cout << "\n\nEnter your choice : ......";
                int n;
                cin >> n;
                if (n == 6)return;
                while (n > 5 || n < 0) {
                    cout << " Your choice is not clear, please re-choice :.....";
                    cin >> n;
                }
                cout << endl;
                if (n == 1) {
                    cout << "Enter the new passenger ID :....";
                    cin >> p4.id_pass;
                } else if (n == 2) {
                    cout << "Enter the new passenger's name :....";
                    cin >> p4.name_pass;
                } else if (n == 3) {
                    cout << "Enter the new plane ID :....";
                    cin >> p4.id_pla;
                } else if (n == 4) {
                    cout << "Enter the new country :....";
                    cin >> p4.city;
                } else if (n == 5) {
                    cout << "Enter the new price. :....";
                    cin >> p4.price;
                }

                in.seekp((int) in.tellg() - sizeof(p4), ios::beg);
                in.write((char *) &p4, sizeof(p4));
                found = true;
            }
            in.read((char *) &p4, sizeof(p4));
        }
        if (!found) {
            cout << "\n\n******************************\n";
            cout << "** This data does not exist **\n";
            cout << "******************************\n";
            cout << "\n\n";
        }
    } else
        cout << "Can not open the specified file";
}

void add_crew_information() {
    crew c;
    ofstream in_crew("addcrew.txt", ios::out | ios::app);
    cout << "Please enter the employee ID : ";
    cin >> c.emp_id;
    cout << "Please enter the name of employee : ";
    cin >> c.emp_name;
    cout << "Please enter the plane ID : ";
    cin >> c.plane_id;
    cout << "Please enter employee salary : ";
    cin >> c.sale;
    in_crew.write((char *) &c, sizeof(c));
    in_crew.close();
}

void view_crew() {
    crew c;
    ifstream ocrew("addcrew.txt", ios::in);
    cout << "---------------------------------------------------------------------------\n";
    cout << "Employee ID   ::   Employee's name   ::   Plane ID   ::   Employee Salary  \n";
    cout << "---------------------------------------------------------------------------\n";
    ocrew.read((char *) &c, sizeof(c));
    while (!ocrew.eof()) {
        string s = c.emp_id, m = "Employee ID   ";
        editspace(sz(m), s);
        cout << "::";
        s = c.emp_name, m = "   Employee's name   ";
        editspace(sz(m), s);
        cout << "::";
        s = c.plane_id, m = "   Plane ID   ";
        editspace(sz(m), s);
        cout << "::";
        s = to_string(c.sale), m = "   Employee Salary  ";
        editspace(sz(m), s);
        cout << "\n";
        cout << "---------------------------------------------------------------------------\n";
        ocrew.read((char *) &c, sizeof(c));
    }
    ocrew.close();
}

void search_crew() {
    crew c;
    ifstream ocrew("addcrew.txt", ios::in);
    ocrew.read((char *) &c, sizeof(c));
    bool check = true;
    cout << "\n\n1-Search by Employee ID.\n";
    cout << "2-Search by Employee's name.\n";
    cout << "3-Search by Plane ID.\n";
    cout << "4-Search by Employee Salary.\n";
    cout << "5-Back to last menu.\n";
    cout << "\n\nEnter your choice : ......";
    int n;
    cin >> n;
    if (n == 5)
        return;
    while (n > 4 || n < 0) {
        cout << " Your choice is not clear, please re-choice :.....";
        cin >> n;
    }
    cout << "\n";
    switch (n) {
        case 1:
            cout << "Enter the employee ID you want to search for :...";
            break;
        case 2:
            cout << "Enter the employee's name you want to search for :...";
            break;
        case 3:
            cout << "Enter the plane ID you want to search for :...";
            break;
        case 4:
            cout << "Enter the employee Salary you want to search for :...";
            break;
    }
    string key;
    cin >> key;
    while (!ocrew.eof()) {
        if ((n == 1 && key == c.emp_id) || (n == 2 && key == c.emp_name) || (n == 3 && key == c.plane_id) ||
            (n == 4 && key == to_string(c.sale))) {
            if (check) {
                check = false;

                cout << "---------------------------------------------------------------------------\n";
                cout << "Employee ID   ::   Employee's name   ::   Plane ID   ::   Employee Salary  \n";
                cout << "---------------------------------------------------------------------------\n";
            }
            string s = c.emp_id, m = "Employee ID   ";
            editspace(sz(m), s);
            cout << "::";
            s = c.emp_name, m = "   Employee's name   ";
            editspace(sz(m), s);
            cout << "::";
            s = c.plane_id, m = "   Plane ID   ";
            editspace(sz(m), s);
            cout << "::";
            s = to_string(c.sale), m = "   Employee Salary  ";
            editspace(sz(m), s);
            cout << "\n";
            cout << "---------------------------------------------------------------------------\n";
        }
        ocrew.read((char *) &c, sizeof(c));
    }
    if (check) {
        cout << "\n\n******************************\n";
        cout << "** This data does not exist **\n";
        cout << "******************************\n";
        cout << "\n\n";
    }
    ocrew.close();
}

void delete_crew_information() {
    crew c;
    cout << "Please enter Employee ID  whose data you want to delete : ....";
    string s;
    cin >> s;
    fstream old("addcrew.txt", ios::in | ios::out | ios::app);
    ofstream neew("current.txt", ios::out | ios::app);
    old.read((char *) &c, sizeof(c));
    bool check = true;
    while (!old.eof()) {
        if (c.emp_id != s) {
            neew.write((char *) &c, sizeof(c));
        } else check = false;
        old.read((char *) &c, sizeof(c));
    }
    old.close();
    neew.close();
    if (check) {
        cout << "******************************\n";
        cout << "** This data does not exist **\n";
        cout << "******************************\n";
        cout << "\n\n";

    }
    remove("addcrew.txt");
    rename("current.txt", "addcrew.txt");

}

void editcrewtable() {
    cout << "Please enter the employee ID whose data you want to modify :  ....";
    string s;
    cin >> s;
    crew c;
    fstream ino("addcrew.txt", ios::in | ios::out);
    ino.read((char *) &c, sizeof(c));
    bool check = true;
    while (!ino.eof()) {
        if (s == c.emp_id) {
            cout << endl << endl;
            cout << "\n1-Modify the Employee name.";
            cout << "\n2-Modify the ID of plane.";
            cout << "\n3-Modify the Employee Salary.";
            cout << "\n4-Back to last menu.";
            cout << "\n\nEnter your choice : ......";
            int n;
            cin >> n;
            if (n == 4)return;
            while (n > 3 || n < 0) {
                cout << " Your choice is not clear, please re-choice :.....";
                cin >> n;
            }
            check = false;
            if (n == 1) {
                cout << "Enter the new employee name :....";
                cin >> c.emp_name;
            } else if (n == 2) {
                cout << "Enter the new plane id :....";
                cin >> c.plane_id;
            } else if (n == 3) {
                cout << "Enter the new Employee Salary :....";
                cin >> c.sale;
            }

            ino.seekp((int) ino.tellg() - sizeof(c), ios::beg);
            ino.write((char *) &c, sizeof(c));
        }
        ino.read((char *) &c, sizeof(c));
    }
    if (check) {
        cout << "******************************\n";
        cout << "** This data does not exist **\n";
        cout << "******************************\n";
        cout << "\n\n";
    }


}

void plane_information() {

    cout << "\n\n1-Add aircraft data.\n";
    cout << "2-View aircraft spreadsheet.\n";
    cout << "3-Search for aircraft data.\n";
    cout << "4-Erase aircraft data.\n";
    cout << "5-Edit aircraft data.\n";
    cout << "6-Back to main menu.\n\n";
    int n;
    cout << "Enter your choice......";
    sha:
    cin >> n;
    switch (n) {
        case 6:
            return;
        case 1:
            cout << endl;
            add_plans_information();
            break;
        case 2:
            view_plan();
            break;
        case 3:
            search_plan();
            break;
        case 4:
            delete_plan_information();
            break;
        case 5:
            editplantable();
            break;
        default:
            cout << " Your choice is not clear, please re-choice :.....";
            goto sha;

    }
    cout << "\nDo you want other services from planes system ? ( YES | NO )....";
    string key;
    cin >> key;
    if (key == "YES" || key == "yes" || key == "Yes" || key == "y") plane_information();
}

void crew_information() {
    cout << "\n\n1-Add employee data.";
    cout << "\n2-View the crew spreadsheet.";
    cout << "\n3-Search for employee data.";
    cout << "\n4-Erase employee data.";
    cout << "\n5-Edit employee data.";
    cout << "\n6-Back to main menu.\n\n";
    int n;
    cout << "Enter your choice......";
    sha:
    cin >> n;
    switch (n) {
        case 6:
            return;
        case 1:
            cout << endl;
            add_crew_information();
            break;
        case 2:
            view_crew();
            break;
        case 3:
            search_crew();
            break;
        case 4:
            delete_crew_information();
            break;
        case 5:
            editcrewtable();
            break;
        default:
            cout << " Your choice is not clear, please re-choice :.....";
            goto sha;

    }
    cout << "\nDo you want other services from Crew System ? ( YES | NO )....";
    string key;
    cin >> key;
    if (key == "YES" || key == "yes" || key == "Yes" || key == "y") crew_information();

}

void passenger_information() {
    cout << "\n\n1-Add passenger data.";
    cout << "\n2-View the passenger spreadsheet.";
    cout << "\n3-Search for passenger data.";
    cout << "\n4-Erase passenger data.";
    cout << "\n5-Edit passenger data.";
    cout << "\n6-Back to main menu.\n\n";
    int n;
    cout << "Enter your choice......";
    sha:
    cin >> n;
    switch (n) {
        case 6:
            return;
        case 1:
            cout << endl;
            add_passanger_information();
            break;
        case 2:
            view_passenger();
            break;
        case 3:
            search_passenger();
            break;
        case 4:
            delete_passenger_information();
            break;
        case 5:
            editpassengertable();
            break;
        default:
            cout << " Your choice is not clear, please re-choice :.....";
            goto sha;

    }
    cout << "\nDo you want other services from Passenger System ? ( YES | NO )....";
    string key;
    cin >> key;
    if (key == "YES" || key == "yes" || key == "Yes" || key == "y") passenger_information();
}


int main() {
    Shahoda:
    cout << "1-Planes System. \n2-Passenger System.\n3-Crew System.\n4-Close System.\n\nEnter your choice : ....";
    Sooo:
    int n;
    cin >> n;
    switch (n) {
        case 1:
            plane_information();
            break;
        case 2:
            passenger_information();
            break;
        case 3:
            crew_information();
            break;
        case 4:
            return 0;
        default:
            cout << " Your choice is not clear, please re-choice :.....";
            goto Sooo;

    }
    cout << "\nDo you want other services from system ? ( YES | NO )....";
    string key;
    cin >> key;
    if (key == "YES" || key == "yes" || key == "Yes" || key == "y") goto Shahoda;


    return 0;
}
