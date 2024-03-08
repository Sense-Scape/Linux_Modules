#include "LinuxWAVReaderModule.h"

LinuxWAVReaderModule::LinuxWAVReaderModule(std::string sFileReadPath, uint32_t u32ChunkSize, unsigned uMaxInputBufferSize) : BaseModule(uMaxInputBufferSize),
                                                                                                                             m_sFileReadPath(sFileReadPath),
                                                                                                                             m_u32ChunkSize(u32ChunkSize),
                                                                                                                             m_vsFileList()
{
    SetInputWAVFileList();
}

void LinuxWAVReaderModule::Process(std::shared_ptr<BaseChunk> pBaseChunk)
{

    // check if currently reading

    // if not open file and store as memeber

    // otherwise carry on reading

    // once read convert to time chunk

    // pass it on
    std::shared_ptr<TimeChunk> pTimeChunk = nullptr;
    if (!TryPassChunk(std::static_pointer_cast<BaseChunk>(pTimeChunk)))
    {
        std::string strWarning = std::string(__FUNCTION__) + ": Next buffer full, dropping current chunk and passing \n";
        PLOG_WARNING << strWarning;
    }

    // and then sleep for the amount of time that was sent in chunk
    auto fChunkDuration_seconds = 1.0f;
    std::this_thread::sleep_for(std::chrono::milliseconds((uint32_t)(1000 * fChunkDuration_seconds)));
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
