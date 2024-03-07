#ifndef WAV_READER_MODULE
#define WAV_READER_MODULE

/*Standard Includes*/
#include <time.h>
#include <iostream>
#include <filesystem>
#include <vector>

/*Custom Includes*/
#include "BaseModule.h"
#include "WAVChunk.h"

class LinuxWAVReaderModule : public BaseModule
{

private:
    std::string m_sFileReadPath; ///< String from where files shall be read
    std::vector<std::string> m_vsFileList;

    /*
     * @brief updates the list of palyable files using specificed member direcotry
     */
    void SetInputWAVFileList();

protected:
    /*
     * @brief Module process to write WAV file
     */
    void Process(std::shared_ptr<BaseChunk> pBaseChunk) override;

public:
    /*
     * Constructor
     * @param[in] sFileReadPath path from which WAV files shall be read
     * @param[in] uMaxInputBufferSize size of input buffer
     */
    LinuxWAVReaderModule(std::string sFileReadPath, unsigned uMaxInputBufferSize);
    ~LinuxWAVReaderModule(){};

    /*
     * @brief Returns module type
     * @param[out] ModuleType of processing module
     */
    std::string GetModuleType() override { return "LinuxWAVReaderModule"; };
};

#endif