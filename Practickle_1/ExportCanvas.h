#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H
#include <iostream>
#include "Canvas.h"

class ExportCanvas {
    public:
        ExportCanvas(Canvas* canvas) : canvas(canvas) {}
        ~ExportCanvas();
        void exportToFile();
    protected:
        Canvas* canvas;
    private:
        virtual void prepareCanvas() = 0;
        virtual void renderElements() = 0;
        virtual void saveToFile() = 0;
};

class PNGExporter : public ExportCanvas {
    public:
        PNGExporter(Canvas* canvas) : ExportCanvas(canvas) {}
        void prepareCanvas() override;
        void renderElements() override;
        void saveToFile() override;
};

class PDFExporter : public ExportCanvas {
    public:
        PDFExporter(Canvas* canvas) : ExportCanvas(canvas) {}
        void prepareCanvas() override;
        void renderElements() override;
        void saveToFile() override;
};

#endif