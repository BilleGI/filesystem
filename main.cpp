#include <iostream>
#include <list>
#include <filesystem>

auto recursiveGetFileNamesByExtension = [](std::filesystem::path& path, const std::string& extension)
{
    std::list<std::string>  list_files;
    path.filename();
    for(auto& p:std::filesystem::recursive_directory_iterator(path))
    {
        if(p.is_regular_file() && (p.path().extension() == extension))
        {
            list_files.push_back(static_cast<std::string> (p.path().filename()));
        }
    }
    return list_files;
};

int main()
{
    std::filesystem::path path("./");
//    std::filesystem::path path("/home/ilya/C++/Module35/HomeWork/third");
    std::string extension;
    std::cout << "The program search file. " << std::endl;
    std::cout << "Enter the extension: ";
    getline(std::cin, extension);
    extension = '.' + extension;
    auto list_files = recursiveGetFileNamesByExtension(path, extension);
    for(auto& it : list_files)
    {
        std::cout << it << std::endl;
    }
    return 0;
}
