#include "ConsoleReader.h"
#include "ConsoleWriter.h"

#include "MedianManager.h"

int main()
{
    MedianManager medianManager;

    medianManager.setReader(new ConsoleReader());
    medianManager.setWriter(new ConsoleWriter());

    std::cout << "Please enter input:" << std::endl;

    medianManager.start();

    return 0;
}
