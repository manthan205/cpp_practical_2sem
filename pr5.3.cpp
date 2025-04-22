#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Point {
public:
    float x, y;

    Point(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    // Overloaded unary operator for negation
    Point operator-() const {
        return Point(-x, -y);
    }

    // Overloaded binary operator for addition
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overloaded equality operator
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    // Display point coordinates
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Abstract base class for operations
class Operation {
public:
    virtual ~Operation() {}
    virtual void execute(Point& point) = 0;
    virtual void undo(Point& point) = 0;
};

// Class for addition operation
class AddOperation : public Operation {
    Point pointToAdd;

public:
    AddOperation(const Point& p) : pointToAdd(p) {}

    void execute(Point& point) override {
        point = point + pointToAdd;
    }

    void undo(Point& point) override {
        point = point + (-pointToAdd);
    }
};

// Class for negation operation
class NegateOperation : public Operation {
public:
    void execute(Point& point) override {
        point = -point;
    }

    void undo(Point& point) override {
        point = -point; // Negating again brings it back
    }
};

// Stack structure for operations
class OperationStack {
    vector<shared_ptr<Operation>> operations;

public:
    void push(shared_ptr<Operation> operation) {
        operations.push_back(operation);
    }

    void undo(Point& point) {
        if (!operations.empty()) {
            operations.back()->undo(point);
            operations.pop_back();
        } else {
            cout << "No operations to undo." << endl;
        }
    }

    void clear() {
        operations.clear();
    }
};

int main() {
    float x, y;

    // Input initial coordinates for Point
    cout << "Enter the initial coordinates of the point (x y): ";
    cin >> x >> y;
    Point p1(x, y);

    OperationStack operationStack;

    int choice;
    while (true) {
        cout << "\nCurrent point: ";
        p1.display();

        cout << "Choose an operation:" << endl;
        cout << "1. Add a point" << endl;
        cout << "2. Negate the point" << endl;
        cout << "3. Undo last operation" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            float addX, addY;
            cout << "Enter the coordinates to add (x y): ";
            cin >> addX >> addY;
            Point p2(addX, addY);
            auto addOp = make_shared<AddOperation>(p2);
            addOp->execute(p1);
            operationStack.push(addOp);
        } else if (choice == 2) {
            NegateOperation negateOp;
            negateOp.execute(p1);
            operationStack.push(make_shared<NegateOperation>(negateOp));
        } else if (choice == 3) {
            operationStack.undo(p1);
        } else if (choice == 4) {
            break; // exit the loop
        } else {
            cout << "Invalid choice. Please choose again." << endl;
        }
    }

    cout << "24CE103_Manthan Rangpariya" << endl;

    return 0;
}
