X = zeros(1,64);
X(16:48)=ones(1,48-15);
Fs = 64;            % Sampling frequency
T = 1/Fs;             % Sampling period
L = 64;             % Length of signal
t = (0:L-1)*T;        % Time vector

Y = fft(X);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

f = Fs*(0:(L/2))/L;

plot(f,P1)
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')