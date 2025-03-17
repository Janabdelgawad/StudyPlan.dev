#include <iostream>
#include <memory>

struct Subresource {
  Subresource(){
    std::cout << "Creating subresource\n";
  };

  Subresource(const Subresource& Source) {
    std::cout
      << "Copying subresource (expensive!)\n";
  }
};

struct Resource {
  // Default constructor
  Resource()
    : Sub{std::make_unique<Subresource>()} {
    std::cout << "Creating resource\n";
  }

  // Copy constructor
  Resource(const Resource& Source)
    : Sub{std::make_unique<Subresource>(
      *Source.Sub)} {
    std::cout << "Copying resource\n";
  }

  // Move constructor
  Resource(Resource&& Source)
    : Sub{std::move(Source.Sub)} {
        std::cout << "Moving resource\n";
    }
  std::unique_ptr<Subresource> Sub;
};

int main(){
    std::cout << "Original Resource\n";
    Resource Original;

    std::cout << "\nCopying Original\n";
    Resource A{Original};

    if(Original.Sub.get())
        std::cout << "Original still has its subresource\n";

    std::cout << "\nMoving Original\n";
    Resource B{std::move(Original)};

    if(!(Original.Sub.get()))
        std::cout << "Original no longer has its subresource\n";
    
    return 0;
}
