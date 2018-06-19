#include <string>

#include "MedianManager.h"

#include "IReader.h"
#include "IWriter.h"

void MedianManager::start()
{
    std::string input;

    while (1)
    {
        mReader->read(input);

        try
        {
            if ("m" == input)
            {
                mWriter->write("Current Median: " + std::to_string(mMedian.median()));
            }
            else if ("q" == input)
            {
                break;
            }
            else
            {
                int value = std::stoi(input);
                mWriter->write("Added value: " + std::to_string(value));
                mMedian.insert(value);
            }
        }
        catch (const std::exception& e)
        {
            mWriter->write(std::string(e.what()));
            continue;
        }
    }
}

void MedianManager::setReader(IReader* reader)
{
    mReader = reader;
}

void MedianManager::setWriter(IWriter* writer)
{
    mWriter = writer;
}
