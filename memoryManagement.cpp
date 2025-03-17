#include <iostream>
#include <vector>
#include <memory>

struct Subresource {
    //default constructor
    Subresource() {
        std::cout << "Creating subresource\n";
    }
    //copy constructor
    Subresource(const Subresource& Source) {
        std::cout << "Copying subreasource (expensive!)\n";
    }
};
struct Resource {
    //resource
    std::unique_ptr<Subresource> Sub;
    //default constructor (new subresource)
    Resource()
        : Sub{std::make_unique<Subresource>()}{
        std::cout << "Creating Resource\n";
    }
    //copy constructor (copied subreasource)
    Resource(const Resource& Source) 
        : Sub{std::make_unique<Subresource>(*Source.Sub)}{
        std::cout << "Copying Resource\n";
    }
};

int main() {
    std::cout << "Resource A:\n";
    Resource A;

    std::vector<Resource> Resources;
    std::cout << "\nMoving it into the vector:\n";
    Resources.push_back(A);
    return 0;
}
