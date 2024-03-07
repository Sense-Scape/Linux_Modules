#include "LinuxWAVReaderModule.h"

LinuxWAVReaderModule::LinuxWAVReaderModule(std::string sFileReadPath, unsigned uMaxInputBufferSize) : BaseModule(uMaxInputBufferSize),
                                                                                                      m_sFileReadPath(sFileReadPath),
                                                                                                      m_vsFileList()
{
    SetInputWAVFileList();
}

void LinuxWAVReaderModule::Process(std::shared_ptr<BaseChunk> pBaseChunk)
{
}

void LinuxWAVReaderModule::SetInputWAVFileList()
{
    // Find all files using dorectory iterator
    for (const auto &entry : std::filesystem::directory_iterator(m_sFileReadPath))
    {
        // The we check if it is wav and store it if it is
        if (entry.is_regular_file() && entry.path().extension() == ".wav")
            m_vsFileList.emplace_back(entry.path().string());
    }

    // Using a range-based for loop
    for (const std::string &sFilePath : m_vsFileList)
    {
        PLOG_INFO << "LinuxWAVReaderModule found: " + sFilePath;
    }
}
