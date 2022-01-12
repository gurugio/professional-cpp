#include <cstddef>
#include <fmt/core.h>
#include "spreadsheet_cell.h"

class SpreadsheetApplication
{
};

class Spreadsheet
{
public:
    Spreadsheet(size_t width,
                size_t height,
                const SpreadsheetApplication &theApp);
    Spreadsheet(const Spreadsheet &src);
    ~Spreadsheet();
    Spreadsheet &operator=(const Spreadsheet &rhs);
    Spreadsheet(Spreadsheet &&src) noexcept;
    Spreadsheet &operator=(Spreadsheet &&rhs) noexcept;

    void setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);
    SpreadsheetCell &getCellAt(size_t x, size_t y);
    const SpreadsheetCell &getCellAt(size_t x, size_t y) const;
    void verifyCoordinate(size_t x, size_t y) const;

    size_t getWidth() { return m_width; }
    size_t getHeight() { return m_height; }

    void swap(Spreadsheet &other) noexcept;

    void pointers()
    {
        for (size_t i{0}; i < m_width; i++)
        {
            std::cout << fmt::format("pointers: m_cell[{}] = {:p}\n",
                                     i, (void *)m_cells[i]);
        }
        std::cout << fmt::format("{:p}\n", (void *)m_cells);
    }

    size_t getID() const;

    static inline const size_t MaxHeight{100};
    static inline const size_t MaxWidth{100};

private:
    void cleanup() noexcept;
    void moveFrom(Spreadsheet &src) noexcept;
    bool inRange(size_t value, size_t upper) const;
    size_t m_width{0};
    size_t m_height{0};
    SpreadsheetCell **m_cells{nullptr};

    static inline size_t ms_counter{0};
    const size_t m_id{0};
    const SpreadsheetApplication &m_theApp;
};