require("PRINT")

function shuffle(t)
	math.randomseed(os.time())
	for i=1, #t do
		local j = math.random(1, #t)
		t[i], t[j] = t[j], t[i]
	end
	return t
end

PRINT(shuffle({1, 2, 3, 4, 5, 6}))