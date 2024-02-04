#!/bin/zsh

ARG="-1 INT_MIN 0 42 22"
echo \>Test1: $ARG\<
./push_swap $ARG
echo ___________
ARG=""
echo \>Test2: $ARG\<
./push_swap $ARG
echo ___________
ARG='-1 INT_MIN 0 42 22'
echo \>Test3: $ARG\<
./push_swap $ARG
echo ___________
ARG="-1 "INT_MIN 0 " 42 22"
echo \>Test4: $ARG\<
./push_swap $ARG
echo ___________
ARG="INT_MAX 0 1 2"
echo \>Test5: $ARG\<
./push_swap $ARG
echo ___________
ARG="1 two 3"
echo \>Test6: $ARG\<
./push_swap $ARG
echo ___________
ARG="1 2 3"
echo \>Test7: $ARG\<
./push_swap $ARG
echo ___________
ARG="1"
echo \>Test8: $ARG\<
./push_swap $ARG
echo ___________
ARG="" 1""
echo \>Test9: $ARG\<
./push_swap $ARG
echo ___________
ARG="42 69 85 14 84 74 1 36 35 43 19 29 60 64 66 59 38 75 76 80 51 40 56 21 25 9 52 90 3 47 5 78 55 79 88 62 68 20 63 94 4 61 71 17 16 99 23 34 33 41 93 37 96 91 39 48 12 53 22 77 30 58 15 8 27 46 11 65 92 50 18 2 100 13 82 87 70 54 95 24 7 45 32 44 6 86 28 26 89 31 57 98 81 72 10 73 97 67 49 83"
echo \>Test10: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="35 53 63 49 86 83 81 14 96 77 4 28 42 88 100 30 51 58 24 34 7 62 48 92 36 57 93 31 6 73 45 94 95 68 39 9 80 33 1 97 91 67 69 19 16 5 60 22 85 32 2 25 29 98 11 17 64 59 13 99 74 40 43 79 21 12 84 44 3 10 37 26 61 50 23 75 15 20 87 65 82 47 55 72 46 76 70 71 18 66 90 78 41 56 54 8 38 89 52 27"
echo \>Test11: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="63 82 9 93 11 1 38 28 30 61 52 91 14 97 67 94 74 5 87 98 49 58 55 16 10 33 34 18 32 44 7 12 73 79 24 86 51 70 77 19 60 23 17 6 41 59 89 36 43 88 29 21 90 4 78 64 46 31 3 71 68 76 37 45 40 75 27 2 47 50 92 35 22 66 42 53 72 57 56 80 13 65 8 26 15 39 25 100 81 54 69 96 95 84 20 85 62 83 48 99"
echo \>Test12: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="22 77 16 66 83 40 90 29 52 21 68 35 70 81 2 100 20 27 46 7 42 31 84 39 33 87 1 92 80 23 32 67 41 59 51 34 82 3 37 43 76 53 50 18 5 55 91 44 36 89 45 6 26 98 8 19 10 15 56 17 93 78 79 24 99 71 74 48 65 64 47 88 49 28 63 95 13 4 25 94 58 97 9 11 54 85 60 86 57 14 73 62 30 38 72 12 96 61 69 75"
echo \>Test13: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="44 70 96 53 98 56 42 50 5 17 99 69 57 13 35 67 51 45 78 8 100 75 89 1 23 74 52 27 59 84 46 25 40 14 49 88 68 81 20 63 73 34 80 97 2 61 79 36 18 24 60 71 83 93 32 28 87 30 82 11 94 54 9 65 64 91 92 66 3 77 6 16 7 31 62 95 76 47 55 58 26 90 12 85 37 38 33 48 29 41 19 4 21 15 39 22 43 10 86 72"
echo \>Test14: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="69 62 24 93 18 59 45 25 51 54 74 47 66 30 86 95 37 98 100 42 13 89 80 12 28 15 71 60 40 57 6 48 82 94 32 96 50 52 16 41 78 22 4 61 63 49 8 68 44 11 75 17 1 99 81 23 39 83 77 43 73 19 70 65 2 21 35 3 14 91 29 55 31 5 72 34 33 84 56 20 85 76 46 10 67 88 97 64 58 87 92 7 9 26 38 53 90 36 79 27"
echo \>Test15: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="9 71 40 21 97 19 34 60 92 66 41 68 15 11 74 48 100 62 26 5 17 80 90 1 37 69 33 8 54 28 55 30 83 4 79 57 99 2 93 49 64 18 65 95 32 43 86 91 51 88 56 24 87 29 81 77 73 96 20 84 7 98 47 14 22 50 36 58 25 13 76 82 75 78 44 45 27 94 31 52 59 38 6 61 42 72 12 10 23 39 70 35 3 85 63 53 46 16 67 89"
echo \>Test16: 100 random no. 1-100 \<
./push_swap $ARG | wc -l
echo ___________
ARG="4 0 2 3 1"
echo \>Test17: $ARG piped to checker\<
./push_swap $ARG
./push_swap $ARG | ./checker $ARG
echo -----------
echo +++++++++++
echo -----------
ARG="0 3 7 8 2 6 4 1 5 9"
echo \>Test18: new alg considerations \for 0 3 7 8 2 6 4 1 5 9\<
echo \>Sketch: \if \< size / 2, ra; \else pb\<
echo 1st round of steps: rra pb ra ra sa pb pb
echo Result =\> A: 2 6 4 1 5 0 3;   B: 7 8 9;
echo 2nd round of steps: ra pb ra sa pb
echo Result =\> A: 1 0 3 2 4;   B: 5 6 7 8 9;
echo 3rd round of steps: sa rra rra rra sa 
echo Result =\> A: 2 3 4 0 1;   B: 5 6 7 8 9;
echo 4th round of steps: rra rra pa ra pa ra pa ra pa ra pa ra
echo Result =\> A: 0 1 2 3 4 5 6 7 8 9;   B: - ;
echo Total steps: 29
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo My original algorithm wins versus this one by 2 steps.
echo ___________
ARG="0 3 7 8 2 6 4 1 5 9"
echo \>Test19: new alg considerations \for 0 3 7 8 2 6 4 1 5 9\<
echo \>Sketch: \if \(topofA \> \(size / 2\)\), ra; \else pb\<
echo 1st round of steps: pb pb rra rra rra pb sb
echo Result =\> A: 5 9 7 8 2 6 4; B: 3 1 0;
echo 2nd round of steps: rra pb rra rra
echo Result =\> A: 2 6 5 9 7 8; B: 4 3 1 0;
echo 3rd round of steps: pb ss
echo Result =\> A: 5 6 9 7 8;   B: 4 2 3 1 0
echo 4th round of steps now that equal sizes, RA-SIFTING AND SWAPPING JE NACH A/B STACK DIRECTION: rr sb
echo Result =\> A: 6 7 9 8 5;   B: 3 2 1 0 4
echo 5th round of steps continued SIFTING \until 'sorted': rr rr sa
echo Result =\> A: 8 9 5 6 7;   B: 1 0 4 3 2
echo 6th round of steps \until \in position: rr rr
echo Result =\> A: 5 6 7 8 9;   B: 4 3 2 1 0
echo 7th round of steps pa \until all \done: pa pa pa pa pa
echo Result =\> A: 0 1 2 3 4 5 6 7 8 9
echo Total steps: 25
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo This one wins versus my original algorithm by 2 steps.
echo ___________
ARG="5 3 8 2 4 1 0 9 6 7"
echo \>Test20: same alg as Test19, \let\'s look at it. 5 3 8 2 4 1 0 9 6 7
echo \>Sketch: \if \(topofA \> \(size / 2\)\), ra, \else pb. sa \where needed\. \if a[z] value adjacent to a[0] value, or b[z] to b[0], get proactive at any step. Or both \if both.\<
echo 1st round of steps: ra pb ra pb sb pb pb rb pb rb
echo Result =\> A: 9 6 7 5 8;   B: 4 3 2 1 0;
echo 2nd round of steps: now that equal sizes, RA-SIFTING AND SWAPPING JE NACH DIRECTION: ra ra sa rra sa
echo Result =\> A: 5 6 7 8 8;   B: 4 3 2 1 0;
echo 3rd round of steps pa \until all \done: pa pa pa pa pa
echo Total steps: 20
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo This one wins versus my original algorithm by 8 steps.
echo ___________
ARG="1 2 0 3 4"
echo \>Test21: same alg as Test19 and Test20, \let\'s look at it. 1 2 0 3 4
echo 1st round of steps: pb pb pb rb pa pa pa
echo Total steps: 7
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo This one wins versus my original algorithm by 3 steps.
echo ___________
ARG="2 3 4 1 0"
echo \>Test22: same alg as Test19 thru Test21, \let\'s look at it. 2 3 4 1 0
echo according to previous definitions: ra ra ra sa --- oops unexpected solve, was getting ready to pb!
echo INNOVATION - \if it can be solved by swaps only: ra ra ra sa
echo Total steps: 4
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo My original algorithm wins versus this one by 1 steps.
echo ___________
ARG="2 1 3 4 0"
echo \>Test23: same alg as Test19 thru here, \let\'s look at it. 2 1 3 4 0
echo according to previous definitions: 
echo INNOVATION - \if it can be solved by swaps only: ra ra ra sa
echo Total steps: 4
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
echo My original algorithm wins versus this one by 1 steps.
echo ___________
ARG="1 382 152 97 257 212 108 10 342 397 413 243 468 168 356 439 341 432 182 499 236 272 308 178 464 8 246 487 113 333 301 7 150 307 125 230 224 21 399 437 154 266 281 156 186 17 89 260 323 367 493 207 120 225 406 366 338 448 444 77 187 436 497 165 347 472 374 129 484 496 247 303 494 221 11 93 393 425 287 466 331 131 359 492 173 470 56 352 36 195 271 202 258 137 294 385 269 389 364 109 30 123 103 92 264 157 205 211 134 316 275 226 217 284 317 240 297 416 153 402 394 213 452 209 304 326 431 332 429 465 167 223 235 88 398 345 176 340 249 456 41 337 18 62 433 79 174 375 4 490 175 282 396 495 73 69 127 192 420 473 469 107 463 370 222 160 391 423 116 228 491 67 163 315 485 52 327 383 442 53 32 309 426 104 239 388 295 70 20 373 37 2 265 48 140 185 39 191 33 84 410 293 220 405 204 290 310 219 475 479 193 233 179 122 106 262 458 6 467 480 486 424 200 455 242 65 321 237 51 311 81 170 197 28 462 360 55 82 274 147 161 111 23 400 105 361 46 124 254 251 286 261 9 61 14 412 415 166 231 110 42 16 183 117 395 80 31 119 379 357 78 438 151 401 336 277 430 348 58 461 268 44 22 149 500 457 60 302 376 381 299 76 488 234 288 377 3 91 171 34 252 428 5 363 404 447 343 64 441 63 434 451 285 449 371 322 489 96 196 435 15 57 351 45 198 460 263 427 199 372 169 409 354 180 421 378 112 279 203 314 143 158 138 216 100 255 477 418 335 346 238 194 90 283 206 86 49 324 59 164 369 386 130 481 126 74 273 172 408 291 474 350 454 407 445 349 390 450 35 483 334 319 414 325 387 144 478 259 87 330 190 232 139 99 244 298 292 159 355 446 250 440 47 318 102 75 241 419 229 101 305 27 71 145 218 72 121 443 329 13 280 270 276 453 177 248 476 189 85 136 141 296 50 339 313 133 155 312 43 253 256 25 54 83 68 132 12 115 300 362 384 411 353 128 24 245 148 181 210 320 392 142 403 498 146 118 98 267 208 95 278 135 29 471 201 344 227 380 38 162 422 214 289 66 368 184 114 215 328 188 94 19 358 482 459 40 26 306 417 365"
echo \>Test24: 500 random no. 1-500 \<
./push_swap $ARG | wc -l
echo ___________
ARG="315 493 171 256 154 96 18 336 263 379 480 387 494 10 22 1 445 476 108 300 54 470 410 360 334 286 312 184 390 152 303 123 245 204 19 441 460 495 163 51 418 65 168 291 449 282 261 138 221 388 188 87 426 392 464 281 109 404 207 125 116 328 158 330 57 414 485 59 149 182 42 456 150 469 372 5 124 46 88 324 97 253 166 269 498 98 210 60 216 318 9 198 468 71 117 364 129 276 176 75 290 95 405 27 148 49 112 411 119 131 122 25 110 172 400 366 177 36 40 346 156 322 76 275 319 395 314 127 481 200 391 344 219 412 323 250 167 106 141 178 151 89 255 85 293 43 444 78 173 199 483 466 29 492 499 203 33 320 227 8 6 32 434 248 490 241 431 174 496 111 232 473 53 192 39 144 113 457 251 489 205 247 101 230 73 16 140 374 21 382 187 378 175 146 41 66 380 38 359 438 201 487 50 463 17 298 272 448 317 461 484 465 114 302 358 475 327 335 135 77 197 226 274 326 14 310 93 305 133 218 451 94 153 105 316 429 384 52 254 332 297 294 341 63 12 427 432 139 266 24 170 228 277 304 262 214 20 56 11 337 301 237 239 190 252 130 234 477 268 398 394 348 236 437 26 415 120 368 399 83 279 347 215 354 107 30 430 143 321 280 61 213 161 363 2 333 31 383 352 413 270 220 447 471 467 180 370 80 82 357 375 264 474 273 13 428 90 160 242 159 157 240 84 295 81 196 191 169 238 362 208 287 64 424 126 100 102 369 103 331 183 500 202 267 349 164 299 436 3 223 257 401 439 186 34 48 233 224 377 478 422 68 311 284 132 420 217 409 288 209 244 260 278 79 99 396 7 458 136 246 165 155 455 367 356 385 406 497 373 147 229 381 386 4 488 292 104 416 459 134 452 86 225 69 44 74 222 325 486 137 15 376 479 442 353 258 446 450 408 365 58 482 309 402 23 491 296 37 62 393 355 329 181 443 243 397 435 454 283 371 440 45 28 265 185 189 162 179 212 417 91 306 433 403 249 193 67 421 343 47 425 142 453 313 231 55 419 289 194 285 72 145 70 115 308 342 307 128 195 339 351 35 338 211 407 271 345 389 350 472 121 92 423 259 118 361 462 235 340 206"
echo \>Test25: 500 random no. 1-500 \<
./push_swap $ARG | wc -l
echo ___________
ARG="232 289 381 441 194 45 216 254 188 285 84 348 184 341 96 218 76 338 207 211 431 415 326 353 390 422 235 205 429 368 108 483 125 440 292 257 284 432 173 389 336 237 31 97 409 147 138 419 388 425 10 405 80 47 127 126 123 395 121 44 444 386 297 318 69 22 65 14 500 377 346 328 417 248 352 305 460 74 319 433 310 101 170 160 259 453 256 21 11 30 479 149 484 120 210 63 263 116 315 105 122 53 159 171 279 461 139 233 128 323 362 270 19 468 227 363 274 330 228 494 349 313 387 345 13 434 249 485 374 95 477 410 331 308 427 141 20 372 55 83 35 106 4 208 264 246 459 407 148 98 239 67 470 467 155 152 88 299 317 371 446 438 478 40 42 463 351 250 50 8 454 28 499 327 312 29 91 343 222 182 333 201 92 252 421 364 358 329 109 195 179 135 151 393 226 164 382 442 261 268 153 287 131 102 300 480 172 219 474 497 424 204 450 361 262 70 276 293 103 392 32 379 428 181 418 404 133 448 115 197 142 272 370 56 192 462 472 129 82 7 112 23 224 202 85 166 162 60 132 412 81 77 332 36 33 288 214 245 367 296 320 269 456 277 113 130 206 3 376 321 18 221 243 265 241 383 213 169 311 43 178 59 189 465 339 291 34 469 397 281 193 280 366 282 451 342 491 452 187 190 498 107 198 306 481 72 369 140 100 78 71 58 490 48 94 458 359 238 290 475 400 303 354 89 307 286 137 325 234 399 114 37 73 119 79 199 145 49 334 165 90 180 2 408 466 61 402 143 176 275 86 420 217 298 488 385 231 144 229 196 255 251 347 253 495 134 435 324 174 5 391 104 493 322 99 87 476 295 167 436 496 230 464 111 223 27 294 473 301 384 437 161 203 283 54 365 247 38 258 200 430 443 157 52 492 46 244 335 156 186 273 75 110 62 487 482 260 316 12 51 314 6 177 242 423 489 220 398 185 278 356 41 457 355 406 413 378 215 486 117 150 471 439 360 39 401 1 26 344 236 17 212 309 93 124 68 175 337 375 373 183 403 24 426 146 225 57 191 168 118 15 64 350 158 25 9 267 16 136 266 302 411 154 414 445 240 340 396 357 209 394 163 447 304 455 66 416 271 449 380"
echo \>Test26: 500 random no. 1-500 \<
./push_swap $ARG | wc -l
echo ___________
ARG="63 376 75 32 92 77 428 313 487 20 465 34 394 482 194 238 475 212 263 79 223 409 250 270 18 390 295 469 6 314 466 418 315 322 319 133 229 304 267 109 89 346 276 321 389 473 37 338 103 55 496 342 195 26 445 78 430 308 312 202 401 53 182 323 252 230 244 262 336 318 56 210 65 224 213 442 284 73 431 316 481 118 193 399 64 425 277 347 377 452 324 209 150 419 215 427 388 15 259 279 28 181 185 381 468 500 287 86 123 170 375 174 46 99 391 203 396 382 164 35 421 113 370 17 330 380 172 395 426 240 298 160 168 368 479 196 143 499 134 407 83 404 57 76 179 126 235 138 48 169 292 294 5 216 405 220 227 437 231 173 406 190 245 369 320 441 251 489 72 269 478 325 470 137 129 379 33 383 191 3 311 333 31 175 156 140 494 485 385 225 350 161 495 340 384 352 207 449 413 167 208 299 275 112 476 85 121 354 176 43 69 423 447 239 256 178 205 310 177 360 296 348 434 444 436 71 457 492 60 124 412 356 74 420 214 306 96 289 24 443 264 7 153 158 339 367 94 162 474 132 335 45 268 440 300 414 253 1 303 25 471 364 188 448 120 460 125 19 462 451 429 9 189 105 283 84 255 355 49 417 13 258 198 219 23 39 408 51 90 54 416 242 271 21 12 357 180 424 272 266 458 67 363 42 102 285 446 95 464 456 200 491 353 187 4 222 372 488 349 351 100 151 345 361 145 61 463 455 88 378 115 14 241 282 104 334 87 211 337 165 327 16 116 108 8 226 22 393 81 206 201 297 293 260 290 248 411 218 154 415 148 107 477 274 38 301 243 131 136 493 40 117 232 387 221 307 36 433 183 111 257 141 146 331 192 438 159 233 41 144 97 236 497 459 373 480 155 422 142 374 80 453 152 309 490 186 280 27 332 119 217 122 166 273 247 498 461 398 403 484 246 317 397 197 204 59 281 328 410 82 291 341 366 326 234 110 228 58 50 400 91 237 128 432 486 439 467 66 359 184 365 30 343 114 402 139 147 101 265 483 10 362 344 278 435 392 171 93 106 261 286 44 29 163 454 98 254 2 68 472 450 47 70 127 386 52 249 329 11 358 199 135 288 371 157 62 305 130 149 302"
echo \>Test27: 500 random no. 1-500 \<
./push_swap $ARG | wc -l
echo ___________
ARG="248 21 234 369 472 431 278 491 358 218 405 429 63 276 51 464 438 289 355 367 76 390 474 286 208 334 480 357 196 189 434 260 291 1 387 245 269 131 462 287 326 29 449 275 242 94 368 132 70 178 200 119 399 290 384 136 500 220 52 225 475 397 450 332 380 209 193 16 35 45 86 497 328 465 476 213 454 254 210 111 340 2 48 314 372 477 188 456 309 283 460 195 3 371 297 466 267 478 110 482 152 6 417 236 410 324 56 115 36 311 233 43 416 146 20 294 318 117 247 347 458 470 39 121 99 420 191 402 173 238 246 274 471 304 171 223 156 308 59 93 349 377 71 395 383 168 202 393 164 473 313 381 145 492 33 413 231 7 199 445 174 92 141 320 451 153 125 134 103 187 485 407 457 179 17 265 235 237 73 118 79 362 227 81 9 264 343 296 18 336 295 459 331 198 95 307 15 394 224 461 13 66 216 365 469 28 436 348 165 253 303 46 42 401 398 68 484 263 391 404 30 428 433 155 244 468 444 102 157 90 133 100 69 85 77 396 104 23 353 83 91 5 400 378 8 57 435 180 185 352 479 354 67 424 418 403 305 183 282 221 148 261 442 302 356 389 159 345 344 107 335 162 97 37 184 333 489 375 240 120 4 486 113 101 257 281 306 415 376 374 379 96 194 382 108 206 252 147 88 217 483 284 226 270 277 34 112 212 127 166 448 493 255 439 258 176 123 430 160 150 298 330 229 105 310 268 137 192 139 423 222 207 41 204 285 455 172 32 426 89 490 219 337 361 169 214 106 197 363 350 443 441 228 44 54 27 452 488 412 323 211 140 158 496 256 317 161 494 55 414 65 272 128 25 316 259 440 342 53 422 47 38 98 122 135 130 453 408 425 50 293 279 129 49 322 232 411 75 327 182 138 292 392 149 373 312 205 201 24 446 40 241 142 249 116 498 432 84 62 406 447 419 481 499 251 170 126 364 114 181 14 463 299 273 351 301 175 467 10 151 230 266 243 427 31 271 325 487 329 321 143 338 421 366 58 74 341 64 109 11 19 346 319 280 163 300 437 190 61 250 177 154 80 72 385 124 359 370 60 12 167 203 495 386 262 360 339 388 186 315 78 22 409 26 144 288 87 82 239 215"
echo \>Test28: 500 random no. 1-500 \<
./push_swap $ARG | wc -l
echo ___________
ARG="392 295 222 483 260 302 376 201 309 326 444 383 342 333 253 16 119 356 297 282 267 235 355 39 15 450 464 278 48 155 137 61 281 269 214 451 458 268 224 27 140 484 217 316 480 67 263 476 117 167 70 462 121 358 191 497 58 317 46 184 57 427 226 273 20 40 419 335 284 308 327 31 369 438 54 17 178 254 125 468 111 384 59 41 123 379 114 197 426 257 431 443 88 73 113 85 414 412 321 166 7 179 373 107 396 250 424 165 366 247 442 108 116 72 216 495 328 1 242 405 343 24 112 240 368 320 106 120 374 371 403 12 207 66 325 486 227 460 101 461 318 127 160 63 319 287 76 208 50 195 148 194 90 285 351 97 28 163 209 234 300 206 26 394 357 4 230 51 277 144 307 32 13 457 354 330 339 173 6 129 489 432 298 74 14 236 241 92 126 314 338 249 42 78 275 53 361 301 196 446 393 175 212 283 375 270 391 69 193 322 189 86 147 459 156 93 139 102 337 96 499 465 21 146 229 475 382 33 81 215 479 60 228 433 470 264 296 168 472 352 441 10 385 395 360 400 481 157 223 473 417 334 421 99 176 152 62 248 365 401 190 372 398 243 19 256 422 344 49 149 258 362 205 279 364 134 288 294 494 188 18 259 416 311 341 345 98 449 64 463 477 261 466 359 115 104 25 232 387 138 68 323 500 381 346 437 225 274 389 331 315 255 471 210 204 171 454 45 353 34 145 100 55 467 491 413 290 174 448 420 312 133 324 452 199 181 305 172 177 447 218 289 439 83 141 456 128 237 65 498 272 82 182 180 220 5 280 496 38 340 418 110 246 154 203 159 29 136 219 304 118 170 131 77 363 478 186 9 80 233 84 306 423 492 44 386 488 271 407 265 162 445 367 158 292 103 329 469 211 428 91 37 388 142 95 35 262 23 124 430 11 348 187 87 482 266 408 435 75 380 455 336 3 409 415 485 105 8 350 276 200 221 130 453 404 2 378 202 434 239 36 436 89 474 153 132 185 151 71 94 291 349 429 299 411 47 56 143 402 493 406 109 238 425 244 310 313 252 213 122 150 79 245 370 52 377 293 397 440 399 164 169 183 303 410 198 161 347 135 390 487 332 192 30 22 286 43 251 490 231"
echo \>Test29: 500 random no. 1-500 \<
./push_swap $ARG | wc -l
echo ___________
ARG="269 499 352 357 183 203 365 471 253 179 201 243 31 240 465 485 428 129 76 410 448 397 165 481 121 302 123 367 446 325 301 175 28 453 291 245 124 260 362 435 376 347 482 498 355 500 78 348 488 300 320 231 267 73 322 45 456 421 172 57 91 85 83 469 139 353 285 439 211 212 242 202 337 467 274 254 314 299 154 316 170 294 143 497 331 19 3 23 62 222 5 474 210 496 176 61 120 125 173 392 282 330 441 431 223 22 454 288 235 389 338 333 462 405 141 466 133 87 272 229 130 262 40 391 185 17 205 276 377 97 406 289 96 43 310 339 423 459 354 236 9 148 344 77 50 204 136 214 256 430 194 268 38 252 434 35 349 450 258 422 486 383 493 452 53 312 396 234 142 8 213 66 306 72 332 266 122 336 458 411 380 279 81 246 46 381 447 200 217 403 363 438 270 144 188 182 159 48 445 477 107 241 88 414 150 51 463 250 13 228 117 360 329 426 1 216 319 407 418 90 54 25 198 219 63 278 127 317 95 476 16 475 249 369 230 387 449 464 118 70 18 37 140 237 366 472 351 164 199 145 321 328 196 442 149 84 89 98 424 295 248 379 93 247 345 128 271 303 478 30 384 281 261 189 75 400 255 455 370 402 60 110 221 80 36 34 157 395 436 304 100 290 160 94 26 49 284 67 27 491 42 68 275 232 327 116 251 226 191 433 335 239 195 432 470 417 168 10 71 298 443 238 343 415 490 292 161 371 74 224 457 135 342 437 296 207 137 468 113 163 99 206 126 356 41 174 138 382 372 451 147 103 106 385 151 388 479 134 359 361 59 460 394 413 297 444 373 398 105 166 368 104 375 192 167 177 495 6 155 197 311 386 440 358 220 393 209 350 461 184 12 265 326 484 313 324 4 56 378 115 404 287 399 473 492 187 364 315 181 7 390 225 158 82 111 280 401 409 55 102 305 293 227 24 33 419 15 323 340 190 408 153 309 146 169 487 427 341 307 263 483 69 132 14 152 32 11 20 86 412 215 178 65 171 374 489 101 186 257 108 156 334 233 318 480 273 92 112 64 162 193 47 21 283 58 208 425 29 277 420 218 2 131 494 114 39 244 264 346 52 119 259 416 79 286 44 308 180 109 429"
echo \>Test30: 500 random no. 1-500 \<
./push_swap $ARG | wc -l
echo ___________
