#include<iostream>
#include<climits>
using namespace std;
long int minimum = INT_MAX;
long int maximum = INT_MIN;

 
int count = 0;

class bst {
public:
    int salary;
    string name;
    string post;
    bst* left;
    bst* right;

    bst(string n, int s, string p) {
        name = n;
        salary = s;
        post = p;
        left = nullptr;
        right = nullptr;
    }
    void create(bst* &root);
    void insert(bst* root, bst* temp);
    void display(bst* root);
    long int sminimum(bst* root);
    long int smaximum(bst* root);
    long int average(bst* root);
    void search(bst* root);
    void update(bst* root); 
};

bst* previous, *root;

void insert(bst* root, bst* temp) {
    if (root == nullptr) {
        return;
    }
    if (temp->salary >= root->salary) {
        while (root != nullptr) {
            previous = root;
            root = root->right;
        }
        previous->right = temp;
    }
    else {
        while (root != NULL) {
            previous = root;
            root = root->left;
        }
        previous->left = temp;
    }
}

void create(bst* &root,string name,long int salary,string post) {
    
    bst* temp = new bst(name, salary, post);
    count++;
    if (root == NULL) {
        root = temp;
        return;
    }
    else {
        insert(root, temp);
    }
}

void display(bst* root) {
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr) {
        display(root->left);
    }
    cout << root->name << "\n";
    cout << root->salary << "\n";
    cout << root->post << "\n";
    if (root->right != nullptr) {
        display(root->right);
    }
}

long int sminimum(bst* root) {
    
    if (root == nullptr) {
        return minimum;
    }
    if (root->salary < minimum) {
        minimum = root->salary;
    }
    if (root->left != nullptr) {
        minimum = sminimum(root->left);
    }
    if (root->right != nullptr) {
        minimum = sminimum(root->right);
    }
    return minimum;
}

long int smaximum(bst* root) {
    long int maximum = INT_MIN;
    if (root == nullptr) {
        return maximum;
    }
    if (root->salary > maximum) {
        maximum = root->salary;
    }
    if (root->left != nullptr) {
        maximum = smaximum(root->left);
    }
    if (root->right != nullptr) {
        maximum = smaximum(root->right);
    }
    return maximum;
}

long int average(bst* root) {
    double total;
    int cnt;
    
    if (root == nullptr) {
        return 0;
    }
    total += root->salary;
      cnt++;
    if (root->left != nullptr) {
        total += average(root->left);
           cnt++;
    }
    if (root->right != nullptr) {
        total += average(root->right);
        cnt++;
    }
    return total;
}

void search(bst* root) {
    string sname;
    long int ssalary;
    cout << "Enter the name to search: ";
    cin >> sname;
    cout << "Enter the salary of employee: ";
    cin >> ssalary;
    if (root == nullptr) {
        return;
    }
    if (root->name == sname) {
        cout << "Employee found!" << endl;
        return;
    }
    if (root->left != nullptr && ssalary < root->salary) {
        search(root->left);
    }
    else {
        if (root->right != nullptr) {
            search(root->right);
        }
    }
}
void update(bst* root) {
    string sname;
    cout << "Enter the name of the employee you want to update: ";
    cin >> sname;

    if (root == nullptr) {
        cout << "Employee not found!" << endl;
        return;
    }

 
    if (root->name == sname) {
        cout << "Employee found ...Current details: " << endl;
        cout << "Name: " << root->name << endl;
        cout << "Salary: " << root->salary << endl;
        cout << "Post: " << root->post << endl;

  
        cout << "Enter new salary: ";
        cin >> root->salary;
        cout << "Enter new post: ";
        cin >> root->post;
        cout << "Employee details updated successfully!" << endl;
        return;
    }

    
    if (root->left != nullptr) {
        update(root->left);  
    }
    if (root->right != nullptr) {
        update(root->right);  
    }
}

void deleteNode(bst* &root, string sname, long int ssalary) {
    if (root == nullptr) {
        return;
    }


    if (root->name == sname && root->salary == ssalary) {
       
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            count--;
            root = nullptr;
            return;
        }

        // Case 2: Node has one child
        if (root->left == nullptr) {
            bst* temp = root->right;
            delete root;
            count--;
            root = temp;
            return;
        } else if (root->right == nullptr) {
            bst* temp = root->left;
            delete root;
            count--;
            root = temp;
            return;
        }

        // Case 3: Node has two children
        // Find the inorder successor (smallest node in the right subtree)
        bst* successor = root->right;
        
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        // Replace the current node with the successor's data
        root->name = successor->name;
        root->salary = successor->salary;
        root->post = successor->post;
        count--;

        // Delete the successor node
        deleteNode(root->right, successor->name, successor->salary);
        return;
    }

    // If the employee is not found, continue searching in the left or right subtrees
    if (ssalary < root->salary) {
        deleteNode(root->left, sname, ssalary);
    } else {
        deleteNode(root->right, sname, ssalary);
    }
}

// Update function added
void fullupdate(bst* root) {
    string sname,newname,newpost;
    long int ssalary,newsalary;
    cout << "Enter the name of the employee you want to update: ";
    cin >> sname;
    cout<<"enter the salary to delete:";
    cin>>ssalary;

    deleteNode(root,sname,ssalary);

    cout<<"enter new salary:";
    cin>>newsalary;
    cout<<"enter new post";
    cin>>newpost;
    newname=sname;
    create(root,newname,newsalary,newpost);
}





int main() {
                 int ch;
                 string name;
                long int salary;
                string post;
                string sname;
            long int ssalary;
    bst* root = nullptr;
    do {
        cout << "Enter the choice:\n1: Add employee\n2: Display all employees\n3: Minimum salary\n4: Maximum salary\n5: Average salary\n6: Total no of employees\n7: Search\n8: delete employee records:\n9:update employee records:\n10:update some information:\n";
        cin >> ch;
        switch (ch) {
            case 1:
            
                
                cout << "Enter the name of employee: ";
                cin >> name;
                cout << "Enter the salary: ";
                cin >> salary;
                cout << "Enter post of employee: ";
                cin >> post;
                
                create(root,name,salary,post);
                break;
            case 2:
                display(root);
                break;
            case 3:
                cout << "Minimum salary: " << sminimum(root) << endl;
                break;
            case 4:
                cout << "Maximum salary: " << smaximum(root) << endl;
                break;
            case 5:
                cout << "Average salary: " << average(root)/count << endl;
                break;
            case 6:
                cout << "Total no of employees: " << count << endl;
                break;
            case 7:
                search(root);
                break;
            case 8:
            
            cout<<"enter the name to delete"; 
            cin>>sname;
            cout<<"enter salary to delete:";
            cin>>ssalary;
                deleteNode(root,sname,ssalary); 
                break;
                case 9:
                fullupdate(root);
                break;
                case 10:
                update(root);
                break;
            
        }
    } while (ch <= 10);
    return 0;
}
