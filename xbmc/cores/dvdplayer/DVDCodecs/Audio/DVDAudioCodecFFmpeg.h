#pragma once

/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "DVDAudioCodec.h"

extern "C" {
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
#include "libswresample/swresample.h"
}

class CDVDAudioCodecFFmpeg : public CDVDAudioCodec
{
public:
  CDVDAudioCodecFFmpeg();
  virtual ~CDVDAudioCodecFFmpeg();
  virtual bool Open(CDVDStreamInfo &hints, CDVDCodecOptions &options);
  virtual void Dispose();
  virtual int Decode(uint8_t* pData, int iSize);
  virtual int GetData(uint8_t** dst);
  virtual void Reset();
  virtual int GetChannels();
  virtual CAEChannelInfo GetChannelMap();
  virtual int GetSampleRate();
  virtual enum AEDataFormat GetDataFormat();
  virtual const char* GetName() { return "FFmpeg"; }
  virtual int GetBitRate();

protected:
<<<<<<< HEAD
  AVCodecContext*     m_pCodecContext;
  enum AVSampleFormat m_iSampleFormat;  
  CAEChannelInfo      m_channelLayout;
=======
  AVCodecContext* m_pCodecContext;
  AVAudioConvert* m_pConvert;;
  enum SampleFormat m_iSampleFormat;
  enum PCMChannels m_channelMap[PCM_MAX_CH + 1];

  BYTE *m_pBuffer1;
  int   m_iBufferSize1;
>>>>>>> FETCH_HEAD

  AVFrame* m_pFrame1;
  int m_gotFrame;

  bool m_bOpenedCodec;
<<<<<<< HEAD
  int      m_channels;
  uint64_t m_layout;
=======
  int m_iBuffered;

  int     m_channels;
  int64_t m_layout;

  DllAvCodec m_dllAvCodec;
  DllAvUtil m_dllAvUtil;
>>>>>>> FETCH_HEAD

  void BuildChannelMap();
  void ConvertToFloat();  
};

