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
    local points_table = {}
    for col = 0, size - 1 do
        for row = 0, size - 1 do
            local ps = Points()
            ps.p1.col = col
            ps.p1.row = row
            if col == 0 and row < size - 1 then
                ps.p2.col = col
                ps.p2.row = row + 1
                table.insert(points_table, ps)
            elseif col > 0 and row == size - 1 then
                ps.p2.col = col - 1
                ps.p2.row = row
                table.insert(points_table, ps)
            elseif col == 0 and row == size - 1 then
                break
            else
                ps.p2.col = col - 1
                ps.p2.row = row
                table.insert(points_table, ps)
                local ps = Points()
                ps.p1.col = col
                ps.p1.row = row
                ps.p2.col = col
                ps.p2.row = row + 1
                table.insert(points_table, ps)
            end
        end
    end
    return points_table
end

function equalCells(pt)
    local equal_cells = {}
    for p = 0, #pt - 1 do
        local p1c = pt[p].p1.col
        local p1r = pt[p].p1.row
        local p2c = pt[p].p2.col
        local p2r = pt[p].p2.row
        if state[p1c][p1r] == state[p2c][p2r] then
            table.insert(equal_cells, pt[p])
        end
    end
    return equal_cells
end

function bestStep(pt)
    local max_score = scoreOf(pt[0])
    local s
    for p = 1, #pt - 1 do
        if scoreOf(pt[p]) > max_score then
            max_score = scoreOf(pt[p])
            s = p
        end
    end
    return pt[s]
end

function scoreOf(points)
    local merge_cells = state[points.p1.col][points.p1.row] * 2
    local steps_number = countSteps(points)
    local result = merge_cells * steps_number
    return result
end
