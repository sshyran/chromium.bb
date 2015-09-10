/*
 * Copyright (C) 2011 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "platform/scroll/ScrollbarThemeMock.h"

#include "platform/RuntimeEnabledFeatures.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/paint/DrawingRecorder.h"
#include "platform/scroll/ScrollbarThemeClient.h"

namespace blink {

static int cScrollbarThickness[] = { 15, 11 };

IntRect ScrollbarThemeMock::trackRect(ScrollbarThemeClient* scrollbar, bool)
{
    return scrollbar->frameRect();
}

int ScrollbarThemeMock::scrollbarThickness(ScrollbarControlSize controlSize)
{
    return cScrollbarThickness[controlSize];
}

bool ScrollbarThemeMock::usesOverlayScrollbars() const
{
    return RuntimeEnabledFeatures::overlayScrollbarsEnabled();
}

void ScrollbarThemeMock::paintTrackBackground(GraphicsContext* context, ScrollbarThemeClient* scrollbar, const IntRect& trackRect)
{
    if (DrawingRecorder::useCachedDrawingIfPossible(*context, *scrollbar, DisplayItem::ScrollbarTrackBackground))
        return;

    DrawingRecorder recorder(*context, *scrollbar, DisplayItem::ScrollbarTrackBackground, trackRect);
    context->fillRect(trackRect, scrollbar->enabled() ? Color::lightGray : Color(0xFFE0E0E0));
}

void ScrollbarThemeMock::paintThumb(GraphicsContext* context, ScrollbarThemeClient* scrollbar, const IntRect& thumbRect)
{
    if (!scrollbar->enabled())
        return;

    if (DrawingRecorder::useCachedDrawingIfPossible(*context, *scrollbar, DisplayItem::ScrollbarThumb))
        return;

    DrawingRecorder recorder(*context, *scrollbar, DisplayItem::ScrollbarThumb, thumbRect);
    context->fillRect(thumbRect, Color::darkGray);
}

}

