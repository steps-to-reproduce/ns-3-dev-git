/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2019 NITK Surathkal
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Shikha Bakshi <shikhabakshi912@gmail.com>
 *         Mohit P. Tahiliani <tahiliani@nitk.edu.in>
           Keerthana Polkampally <keerthana.keetu.p@gmail.com>
           Archana Priyadarshani Sahoo <archana98priya@gmail.com>
           Durvesh Shyam  Bhalekar <durvesh.5.db@gmail.com>
 */
#pragma once

#include "ns3/object.h"
#include "ns3/traced-value.h"
#include "ns3/sequence-number.h"
#include "ns3/nstime.h"
#include "ns3/tcp-option-sack.h"
#include "ns3/packet.h"
#include "ns3/tcp-socket-state.h"
#include "ns3/simulator.h"

namespace ns3 {

class TcpTlp : public Object
{
public:
  //brief Get the type ID.
  //return the object TypeId
  static TypeId GetTypeId (void);
  //brief Constructor
  TcpTlp ();
  //brief Copy constructor.
  //param other object to copy.
  TcpTlp (const TcpTlp &other);

  //brief Deconstructor
  virtual ~TcpTlp ();

  Time CalculatePto(Time srtt, uint32_t flightsize, double rto);

  private:

    double           m_srtt                      {0}; //!< Smoothened RTT (SRTT) as specified in [RFC6298]
    double           m_alpha                 {0.125}; //!< EWMA constant for calculation of SRTT (alpha = 1/8)

    Time             m_pto                       {0}; //!< PTO values>
    Time             m_tlpRtt                    {0}; //!< RTT value used for TLP>
};
}
