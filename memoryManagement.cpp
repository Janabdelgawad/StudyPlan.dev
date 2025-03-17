#include <iostream>

struct Resource {
  // Default constructor
  Resource() {}

  // Copy constructor
  Resource(const Resource& Source) {
    std::cout << "Copying resource\n";
  }

  // Move constructor
  Resource(Resource&& Source) {
    std::cout << "Moving resource\n";
  }
};
int main() {
    std::cout << "Original resource\n";
    Resource Original;

    std::cout << "\nresource A:\n";
    Resource A{Original};

    std::cout << "\nresource B:\n";
    Resource B{std::move(Original)};
    return 0;
}
