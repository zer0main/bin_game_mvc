--[[
Global variables:
* int size
* state[0-col][0-row] = value of cell

Functions called from C++:
* int getDeskSize()
* int getWinNumber()
* int getTimeNumber()
* 0-int, 0-int, 0-int, 0-int getIndex()
    returns coordinates of joined cells
* output(model)
    provides current state of game

model has the following methods:
* int getDeskNumber(point)
    returns value of cell

Point has the following fields:
* 0-int col
* 0-int row

Points has the following fields:
* Point p1
* Point p2

type points_table:
is array of instances of Points

Utility lua-functions (not called from C++ directly):
* points_table searchNearbyCells()
    returns points_table of all nearby points
* points_table equalCells(points_table)
    returns table of equal points (filters points_table)
* int scoreOf(points)
    returns score of the points.
    This function counts possible steps on the next step
    after applying points and multiplies it with
    value of merged cells.
* points bestStep(points_table)
    returns the best points for new step from points_table.
    Uses scoreOf as scoring function.
--]]

math = require('math')
local state
local size

function getDeskSize()
    size = math.random(2, 9)
    state = {}
    for i = 0, size - 1 do
        state[i] = {}
    end
    return size
end

function getWinNumber()
    return math.random(200, 1000)
end

function getTimeNumber()
    return math.random(1, 10)
end

function output(model)
    local p = Point()
    for col = 0, size -1 do
        for row = 0, size - 1 do
            state[col][row] = model:getDeskNumber(p)
        end
    end
end

function getIndex()
    local nearby_points = searchNearbyCells()
    local equal_points = equalCells(nearby_points)
    local p = bestStep(equal_points)
    return p.p1.col, p.p1.row, p.p2.col, p.p2.row
end

function searchNearbyCells()
    local ps = Points()
    local points_table = {}
    local i = 0
    for col = 0, size - 1 do
        for row = 0, size - 1 do
            ps.p1.col = col
            ps.p1.row = row
            if col == 0 and row < size - 1 then
                ps.p2.col = col
                ps.p2.row = row + 1
                points_table[i] = ps
                i = i + 1
            elseif col > 0 and row == size - 1 then
                ps.p2.col = col - 1
                ps.p2.row = row
                points_table[i] = ps
                i = i + 1
            elseif col == 0 and row == size - 1 then
                break
            else
                ps.p2.col = col - 1
                ps.p2.row = row
                points_table[i] = ps
                ps.p2.col = col
                ps.p2.row = row + 1
                i = i + 1
                points_table[i] = ps
                i = i + 1
            end
        end
    end
    return points_table
end
