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
* int getDeskSize()
* int getDeskNumber(point)
    returns value of cell

Point has the following fields:
* 0-int col
* 0-int row

Points has the following fields:
* Point p1
* Point p2

Utility lua-functions (not called from C++ directly):
* table searchNearbyCells()
    returns table of all nearby points combined in 
    Points structures
* table equalityCells(nearby_cells_table)
    returns table of equality points (filter nearby_cells_table)
* int countSteps(points)
    returns number of possible steps on the next step described by
    argument points
* points bestStep(points_table)
    returns the best points for new step form points_table
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
