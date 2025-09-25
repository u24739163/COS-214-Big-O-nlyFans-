#include "ExportCanvas.h"

void ExportCanvas::exportToFile() 
{
    // Implementation for exporting the canvas to a file
    prepareCanvas();
    renderElements();
    saveToFile();
}

void ExportCanvas::prepareCanvas() 
{
    std::cout << "Preparing canvas for export." << std::endl;
}

void ExportCanvas::renderElements() 
{
    std::cout << "Rendering elements on the canvas." << std::endl;
}

void PNGExporter::saveToFile() 
{
    std::cout << "Saving canvas as PNG file." << std::endl;
}

void PNGExporter::prepareCanvas() 
{
    std::cout << "Prepping Canvas for PNG export." << std::endl;
}

void PNGExporter::renderElements() 
{
    std::cout << "Rendering elements for PNG export." << std::endl;
}

void PDFExporter::prepareCanvas() 
{
    std::cout << "Prepping Canvas for PDF export." << std::endl;
}

void PDFExporter::renderElements() 
{
    std::cout << "Rendering elements for PDF export." << std::endl;
}

void PDFExporter::saveToFile() 
{
    std::cout << "Saving canvas as PDF file." << std::endl;
}

ExportCanvas::~ExportCanvas() 
{
    std::cout << "ExportCanvas destructor called." << std::endl;
}