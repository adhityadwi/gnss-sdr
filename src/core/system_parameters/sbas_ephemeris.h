/*
 * \file sbas_ephemeris.h
 * \brief  Implementation of a SBAS REFERENCE LOCATION storage
 *
 * \author Daniel Fehr, 2013. daniel.co(at)bluewin.ch
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


#ifndef GNSS_SDR_SBAS_EPHEMERIS_H_
#define GNSS_SDR_SBAS_EPHEMERIS_H_


class Sbas_Ephemeris
{
public:
    void print(std::ostream &out);
    int i_prn;            // PRN number */
    //gtime_t t0;         // reference epoch time (GPST)
    int i_t0;
    //gtime_t tof;        // time of message frame (GPST)
    double d_tof;
    int i_sv_ura;         // SV accuracy (URA index), not standardized
    bool b_sv_do_not_use; // health status (false:don't use / true:usable)
    double d_pos[3];      // satellite position (m) (ecef)
    double d_vel[3];      // satellite velocity (m/s) (ecef)
    double d_acc[3];      // satellite acceleration (m/s^2) (ecef)
    double d_af0;         // satellite clock-offset (s)
    double d_af1;     	  // satellite drift (s/s)
};


#endif /* GNSS_SDR_SBAS_EPHEMERIS_H_ */
