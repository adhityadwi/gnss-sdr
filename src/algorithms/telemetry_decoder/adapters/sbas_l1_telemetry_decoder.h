/*!
 * \file sbas_l1_telemetry_decoder.h
 * \brief Interface of an adapter of a SBAS telemtry data decoder block
 * to a TelemetryDecoderInterface
 * \author Daniel Fehr 2013. daniel.co(at)bluewin.ch
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2013  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */


#ifndef GNSS_SDR_SBAS_L1_TELEMETRY_DECODER_H_
#define GNSS_SDR_SBAS_L1_TELEMETRY_DECODER_H_

#include "telemetry_decoder_interface.h"
#include "sbas_l1_telemetry_decoder_cc.h"
#include <gnuradio/msg_queue.h>


class ConfigurationInterface;

/*!
 * \brief This class implements a NAV data decoder for SBAS frames in L1 radio link
 */
class SbasL1TelemetryDecoder : public TelemetryDecoderInterface
{
public:
    SbasL1TelemetryDecoder(ConfigurationInterface* configuration,
            std::string role,
            unsigned int in_streams,
            unsigned int out_streams,
            boost::shared_ptr<gr::msg_queue> queue);

    virtual ~SbasL1TelemetryDecoder();
    std::string role()
    {
        return role_;
    }

    std::string implementation()
    {
        return "SBAS_L1_Telemetry_Decoder";
    }
    void connect(gr::top_block_sptr top_block);
    void disconnect(gr::top_block_sptr top_block);
    gr::basic_block_sptr get_left_block();
    gr::basic_block_sptr get_right_block();
    void set_satellite(Gnss_Satellite satellite);
    void set_channel(int channel){ telemetry_decoder_->set_channel(channel); }
    void reset()
    {
        return;
    }
    size_t item_size()
    {
        return 0;
    }

private:
    sbas_l1_telemetry_decoder_cc_sptr telemetry_decoder_;
    Gnss_Satellite satellite_;
    int channel_;
    unsigned int vector_length_;
    std::string item_type_;
    bool dump_;
    std::string dump_filename_;
    std::string role_;
    unsigned int in_streams_;
    unsigned int out_streams_;
    boost::shared_ptr<gr::msg_queue> queue_;
};

#endif
