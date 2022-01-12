#include "spreadsheet.h"
#include <fmt/core.h>
#include <cstdint>
#include <algorithm>

using namespace std;
using namespace fmt;

Spreadsheet::Spreadsheet(size_t width, size_t height,
                         const SpreadsheetApplication &theApp)
    : m_width{min(width, Spreadsheet::MaxWidth)},
      m_height{min(height, Spreadsheet::MaxHeight)},
      m_id{ms_counter++},
      m_theApp{theApp}
{
    cout << format("ctor: {}x{}", m_width, m_height) << '\n';
    m_cells = new SpreadsheetCell *[m_width];
    cout << format("new m_cell = {:p}\n", (void *)m_cells);
    for (size_t i{0}; i < m_width; i++)
    {
        m_cells[i] = new SpreadsheetCell[m_height];
        cout << format("new m_cell[{}] = {:p}\n", i, (void *)m_cells[i]);
    }
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= m_width)
    {
        throw out_of_range{fmt::format("{} must be less than {}.", x, m_width)};
    }
    if (y >= m_height)
    {
        throw out_of_range{format("{} must be less than {}.", y, m_height)};
    }
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell &cell)
{
    verifyCoordinate(x, y);
    m_cells[x][y] = cell;
}

const SpreadsheetCell &Spreadsheet::getCellAt(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

SpreadsheetCell &Spreadsheet::getCellAt(size_t x, size_t y)
{
    cout << "const_cast pattern\n";
    return const_cast<SpreadsheetCell &>(as_const(*this).getCellAt(x, y));
}

Spreadsheet::~Spreadsheet()
{
    for (size_t i{0}; i < m_width; i++)
    {
        cout << format("delete m_cell[{}] = {:p}\n", i, (void *)m_cells[i]);
        delete[] m_cells[i];
        m_cells[i] = 0;
    }
    cout << format("delete m_cell = {:p}\n", (void *)m_cells);
    delete[] m_cells;
    m_cells = nullptr;
}

Spreadsheet::Spreadsheet(const Spreadsheet &src)
    : Spreadsheet{src.m_width, src.m_height, src.m_theApp}
{
    cout << "spreadsheet copy-ctor\n";
    for (size_t i{0}; i < m_width; i++)
    {
        for (size_t j{0}; j < m_height; j++)
        {
            m_cells[i][j] = src.m_cells[i][j];
        }
    }
}

void Spreadsheet::swap(Spreadsheet &other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

Spreadsheet &Spreadsheet::operator=(const Spreadsheet &rhs)
{
    cout << "spreadsheet assign-ctor\n";
    Spreadsheet temp{rhs};
    swap(temp);
    return *this;
}

void Spreadsheet::cleanup() noexcept
{
    for (size_t i{0}; i < m_width; i++)
    {
        cout << "cleanup cell\n";
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = nullptr;
    m_width = m_height = 0;
}

void Spreadsheet::moveFrom(Spreadsheet &src) noexcept
{
    m_width = exchange(src.m_width, 0);
    m_height = exchange(src.m_height, 0);
    m_cells = exchange(src.m_cells, nullptr);
}

static void swapSpreadsheet(Spreadsheet &lhs, Spreadsheet &rhs) noexcept
{
    lhs.swap(rhs);
}

Spreadsheet::Spreadsheet(Spreadsheet &&src) noexcept
    : m_theApp{src.m_theApp}
{
    cout << "move ctor\n";
    // moveFrom(src);
    swapSpreadsheet(*this, src);
}

Spreadsheet &Spreadsheet::operator=(Spreadsheet &&rhs) noexcept
{
    cout << "move assign\n";
    /*
   if (this == &rhs)
   {
       return *this;
   }

   cleanup();
   moveFrom(rhs);
*/

    swapSpreadsheet(*this, rhs);
    return *this;
}