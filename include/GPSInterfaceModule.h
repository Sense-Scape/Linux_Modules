#ifndef GPS_INTERFACE_MODULE
#define GPS_INTERFACE_MODULE

/*Linux Includes*/
#include <iostream>
#include <fstream>

/*Custom Includes*/
#include "BaseModule.h"
#include "GPSChunk.h"

/**
 * @brief Class that reads pcm data from linux sound card
 */
class GPSInterfaceModule : public BaseModule
{
public:
    /**
     * @brief TODO
     */
    GPSInterfaceModule(std::string strInterfaceName, std::vector<uint8_t> &vu8SourceIdentifier, unsigned uBufferSize);

    /**
     * @brief Generate and fill complex time data chunk and pass on to next module
     */
    void Process(std::shared_ptr<BaseChunk> pBaseChunk) override;

    /**
     * @brief Returns module type
     * @param[out] ModuleType of processing module
     */
    std::string GetModuleType() override { return "GPSInterfaceModule"; };

    /**
     * @brief Check input buffer and try process data
     */
    void ContinuouslyTryProcess() override;

private:
    std::fstream m_fsSerialInterface;
    std::string m_strInterfaceName;
    std::vector<uint8_t> m_vu8SourceIdentifier; ///< Source identifier of generated chunks

    bool TryOpenSerialInterface();

    bool IsSerialInterfaceOpen();

    void TryTransmitPositionData();

    unsigned char CalculateChecksum(const std::string &sentence);

    std::shared_ptr<GPSChunk> ExtractGSPData(const std::string &sentence);
};

#endif
