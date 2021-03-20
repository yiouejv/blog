












function shuffle(sequence)
    for i, _ in ipairs(sequence) do
        local j = math.random(i, #sequence)
        sequence[i], sequence[j] = sequence[j], sequence[i]
    end
end


local t = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
shuffle(t)
require("PRINT")
PRINT(t)