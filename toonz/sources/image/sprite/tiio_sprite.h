#pragma once

#ifndef TTIO_SPRITE_INCLUDED
#define TTIO_SPRITE_INCLUDED

#include "tproperty.h"
#include "tlevel_io.h"
#include "trasterimage.h"
#include <QVector>
#include <QStringList>
#include <QtGui/QImage>
//===========================================================
//
//  TLevelWriterSprite
//
//===========================================================

class TLevelWriterSprite : public TLevelWriter {
public:
  TLevelWriterSprite(const TFilePath &path, TPropertyGroup *winfo);
  ~TLevelWriterSprite();
  void setFrameRate(double fps);

  TImageWriterP getFrameWriter(TFrameId fid) override;
  void save(const TImageP &image, int frameIndex);

  void saveSoundTrack(TSoundTrack *st);

  static TLevelWriter *create(const TFilePath &path, TPropertyGroup *winfo) {
    return new TLevelWriterSprite(path, winfo);
  }

private:
  int m_lx, m_ly;
  int m_scale;
  int m_topPadding, m_bottomPadding, m_leftPadding, m_rightPadding;
  int m_left = 0, m_right = 0, m_top = 0, m_bottom = 0;
  std::vector<QImage *> m_images;
  std::vector<QImage> m_imagesResized;
  bool m_firstPass = true;
  bool m_trim      = true;
  QString m_format;
  // void *m_buffer;
};

//===========================================================================

namespace Tiio {

//===========================================================================

class SpriteWriterProperties : public TPropertyGroup {
public:
  TEnumProperty m_format;
  TIntProperty m_topPadding, m_bottomPadding, m_leftPadding, m_rightPadding;
  TIntProperty m_scale;
  TBoolProperty m_trim;
  SpriteWriterProperties();
};

//===========================================================================

}  // namespace

#endif
